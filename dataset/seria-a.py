
# coding: utf-8

# In[146]:


import pandas as pd


# In[147]:


df1=pd.read_csv('seriea/2000-2001.csv')
df1=df1[['HomeTeam','AwayTeam','FTR']]
df2=pd.read_csv('seriea/2001-2002.csv')
df2=df2[['HomeTeam','AwayTeam','FTR']]
df3=pd.read_csv('seriea/2002-2003.csv')
df3=df3[['HomeTeam','AwayTeam','FTR']]
df4=pd.read_csv('seriea/2003-2004.csv')
df4=df4[['HomeTeam','AwayTeam','FTR']]
df5=pd.read_csv('seriea/2004-2005.csv')
df5=df5[['HomeTeam','AwayTeam','FTR']]
df6=pd.read_csv('seriea/2005-2006.csv')
df6=df6[['HomeTeam','AwayTeam','FTR']]
df7=pd.read_csv('seriea/2006-2007.csv')
df7=df7[['HomeTeam','AwayTeam','FTR']]
df8=pd.read_csv('seriea/2007-2008.csv')
df8=df8[['HomeTeam','AwayTeam','FTR']]
df9=pd.read_csv('seriea/2008-2009.csv')
df9=df9[['HomeTeam','AwayTeam','FTR']]
df10=pd.read_csv('seriea/2009-2010.csv')
df10=df10[['HomeTeam','AwayTeam','FTR']]
df11=pd.read_csv('seriea/2010-2011.csv')
df11=df11[['HomeTeam','AwayTeam','FTR']]
df12=pd.read_csv('seriea/2011-2012.csv')
df12=df12[['HomeTeam','AwayTeam','FTR']]
df13=pd.read_csv('seriea/2012-2013.csv')
df13=df13[['HomeTeam','AwayTeam','FTR']]
frames = [df1,df2,df3,df4,df5,df6,df7,df8,df9,df10,df11,df12,df13]
df=pd.concat(frames)
df=df.reset_index(drop=True)


# In[148]:


a = ['Como','Venezia','Ancona','Treviso','Novara','Piacenza','Modena','Verona','Cesena','Ascoli','Bari','Messina','Perugia','Vicenza','Pescara']
df = df[~df['HomeTeam'].isin(a)]
df = df[~df['AwayTeam'].isin(a)]
df


# In[149]:


teams = df['HomeTeam'].unique()
print(teams)
df['HomeTeam'].nunique()


# In[150]:


print(df['HomeTeam'].value_counts())


# In[151]:


dicts = {}
j = 0
for i in teams:
        dicts[i] = j
        j=j+1


# In[152]:


print(dicts)


# In[153]:


rows, cols = (24, 24) 
arr = [[0 for i in range(cols)] for j in range(rows)] 
# print(arr)
arr1 = [[0 for i in range(cols)] for j in range(rows)] 
print(arr1)


# In[154]:


for ind in df.index:
  # arr1[dicts[df['HomeTeam'][ind]]][dicts[df['AwayTeam'][ind]]] += 1
  # arr1[dicts[df['AwayTeam'][ind]]][dicts[df['HomeTeam'][ind]]] += 1
  if df['FTR'][ind]=='A' :
    arr[dicts[df['HomeTeam'][ind]]][dicts[df['AwayTeam'][ind]]] += 1
  elif df['FTR'][ind]=='H' :
    arr[dicts[df['AwayTeam'][ind]]][dicts[df['HomeTeam'][ind]]] += 1
  else :
    arr[dicts[df['HomeTeam'][ind]]][dicts[df['AwayTeam'][ind]]] += 0.5
    arr[dicts[df['AwayTeam'][ind]]][dicts[df['HomeTeam'][ind]]] += 0.5


# In[155]:

for i in range(len(arr)):
  for j in range(len(arr[0])):
    arr[i][j] = int(arr[i][j])



# In[156]:

            
print(arr)

