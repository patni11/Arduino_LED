import pandas as pd 
import numpy as np 
import matplotlib.pyplot as plt 
import matplotlib
plt.style.use('classic')
import re
import fileinput
import nltk
from nltk import word_tokenize
from nltk.stem.snowball import SnowballStemmer
from nltk.tokenize import word_tokenize 
import nltk
from itertools import chain
import warnings
import serial
import random
warnings.filterwarnings("ignore", category=DeprecationWarning)
import json
from tqdm import tqdm as tqdm
from tqdm import trange


def extract_emotion(df,column):
    new_df = df.copy()
    Lexicon = 'NRC-Emotion-Lexicon-Wordlevel-v0.92.txt' #path to lexicon file
    
    lex_df = pd.read_csv(Lexicon,names=["word", "emotion", "association"],sep='\t') # creates column names as word, emotion and association
    lex_words = lex_df.pivot(index='word',
                                columns='emotion',
                                values='association').reset_index()   #creates 10 extra columns for each emotion

    emotions = lex_words.columns.drop('word')
    emo_df = pd.DataFrame(0, index = new_df.index,columns=emotions)
    #print(emo_df.head())
    total_df = pd.DataFrame(0,index=new_df.index,columns=['total'])
    stemmer = SnowballStemmer('english')

    with tqdm(total=len(list(new_df.iterrows()))) as pbar:
        for i,rows in new_df.iterrows():
            pbar.update(1)
            long_text = word_tokenize(new_df.loc[i][column])
            for word in long_text:
                word = stemmer.stem(word.lower())
                score = lex_words[lex_words.word == word]
                if not score.empty:
                    for emotion in list(emotions):
                        emo_df.at[i, emotion] += score[emotion]
            
            total = emo_df.sum(axis=1,skipna = True)[i]
            total_df.at[i,'total'] = total

    new_df = pd.concat([new_df,emo_df],axis=1)
    new_df = pd.concat([new_df,total_df],axis = 1)
    return new_df                    

def clean_data(df):
    new_df = df
    vs = new_df.sum(axis = 0, skipna = True)
    emotions_values = {'anger':vs['anger'],'anticipation':vs['anticipation'],'disgust': vs['disgust'],'fear': vs['fear'],'joy':vs['joy'],'sadness': vs['sadness'],'surprise':vs['surprise'],'trust':vs['trust']}
    sentiment = {'negative':vs['negative'],'positive': vs['positive']}
    total = vs['total']   
    total_emotion = total - (vs['negative']+ vs['positive'])
    word_count = vs['word_count']
    return emotions_values,sentiment,total,total_emotion,word_count

def get_rgb(ev,te):

    emotions_color = {'anger':random.randint(0,40),'anticipation':random.randint(30,62),'joy':random.randint(62,80),'trust':random.randint(70,90),'fear': random.randint(90,110),'surprise':random.randint(110,140),'sadness': random.randint(140,200),'disgust': random.randint(200,255)}
    number_each = round(300/te)
    print(number_each)
    
    for each in ev:
        ev[each] *= number_each

    final_colors = {'anger':{'vals':ev['anger'],'color':emotions_color['anger']},
    'anticipation':{'vals':ev['anticipation'],'color':emotions_color['anticipation']},
    'joy':{'vals':ev['joy'],'color':emotions_color['joy']},
    'trust':{'vals':ev['trust'],'color':emotions_color['trust']},
    'fear':{'vals':ev['fear'],'color':emotions_color['fear']},
    'surprise':{'vals':ev['surprise'],'color':emotions_color['surprise']},
    'sadness':{'vals':ev['sadness'],'color':emotions_color['sadness']},
    'disgust':{'vals':ev['disgust'],'color':emotions_color['disgust']}
    }
    return final_colors
    

def main(comment,file='yes'):
    if file=='yes':
        with open('lyrics.txt','r') as f:
            comments = f.readlines()
    else:
        comments = [comment+'\n']
    

    df = pd.DataFrame({'comments':comments})      
    
    new_df = extract_emotion(df,'comments')  
    new_df['word_count'] = new_df['comments'].apply(word_tokenize).apply(len)
    emotions = ['anger', 'anticipation', 'disgust', 'fear', 'joy', 'negative', 'positive', 'sadness', 'surprise', 'trust']

    ev,s,t,te,wc = clean_data(new_df)
    '''
    for emotion in emotions:
        new_df[emotion] = new_df[emotion] / new_df['word_count']
    '''
    weighted_random_emotion_picker = [[keys]*ev[keys] for keys in ev.keys()]
    weighted_random_emotion_picker = list(chain.from_iterable(weighted_random_emotion_picker))  
    
    #get_rgb(weighted_random_emotion_picker,s)
    with open('data.json', 'w') as fp:
        json.dump(get_rgb(ev,te), fp)
    
main('no','yes')

