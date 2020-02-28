
# coding: utf-8

# In[29]:


import io
import pandas as pd


# In[30]:


df=pd.read_csv('barclaysdataset.csv')


# In[31]:


df.head()


# In[32]:


a = ['Charlton Athletic','Cardiff City','Sheffield United','Blackpool','Huddersfield Town','Brighton and Hove Albion','Derby County']
df = df[~df['home_team'].isin(a)]
df = df[~df['away_team'].isin(a)]


# In[33]:


teams = df['home_team'].unique()
print(teams)
df['home_team'].nunique()


# In[34]:


df['home_team'].value_counts()


# In[35]:


dicts = {}
j = 0
for i in teams:
        dicts[i] = j
        j=j+1


# In[36]:


print(dicts)


# In[37]:


rows, cols = (32, 32) 
arr = [[0 for i in range(cols)] for j in range(rows)] 
# print(arr)
arr1 = [[0 for i in range(cols)] for j in range(rows)] 
print(arr1)


# In[38]:


for ind in df.index:
#   print(dicts[df['home_team'][ind]])
#   print(dicts[df['away_team'][ind]])
  arr1[dicts[df['home_team'][ind]]][dicts[df['away_team'][ind]]] += 1
  arr1[dicts[df['away_team'][ind]]][dicts[df['home_team'][ind]]] += 1

  if df['result'][ind]=='H' :
    arr[dicts[df['home_team'][ind]]][dicts[df['away_team'][ind]]] += 1
  elif df['result'][ind]=='A' :
    arr[dicts[df['away_team'][ind]]][dicts[df['home_team'][ind]]] += 1
  else :
    arr[dicts[df['home_team'][ind]]][dicts[df['away_team'][ind]]] += 0.5
    arr[dicts[df['away_team'][ind]]][dicts[df['home_team'][ind]]] += 0.5


# In[39]:


arr


# In[40]:


for i in range(len(arr)):
    for j in range(len(arr[i])):
        if arr[i][j]!= 0 :
            arr[i][j] = arr[i][j]/arr1[i][j]
        else :
            arr[i][j] = 0
            
for i in range(len(arr)):
    st=""
    for j in range(len(arr[i])):
      st+=str(arr[i][j])+","
    st = st[:-1]
    print(st)



for i in teams:
  print(i),