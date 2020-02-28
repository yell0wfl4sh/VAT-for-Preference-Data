
# coding: utf-8

# In[29]:


import io
import pandas as pd


# In[30]:


df=pd.read_csv('barclaysdataset.csv')


# In[31]:


print(df.head())


# In[32]:


a = ['Charlton Athletic','Cardiff City','Sheffield United','Blackpool','Huddersfield Town','Brighton and Hove Albion','Derby County','Queens Park Rangers','Wolverhampton Wanderers','AFC Bournemouth','Birmingham City','Reading']
df = df[~df['home_team'].isin(a)]
df = df[~df['away_team'].isin(a)]


# In[33]:


teams = df['home_team'].unique()
print(teams)
print(df['home_team'].nunique())

pre = [[0 for i in range(4)] for j in range(len(teams))] 
for i in range(len(teams)):
  for ind in df.index:
    if teams[i]==df['home_team'][ind]:
      pre[i][3]+=1
      if df['result'][ind]=="H":
        pre[i][0]+=1
      elif df['result'][ind]=="D":
        pre[i][2]+=1
      else:
        pre[i][1]+=1
    elif teams[i]==df['away_team'][ind]:
      pre[i][3]+=1
      if df['result'][ind]=="H":
        pre[i][2]+=1
      elif df['result'][ind]=="D":
        pre[i][0]+=1
      else:
        pre[i][1]+=1



for i in range(len(pre)):
  st=""
  st+=teams[i]+","
  for j in range(4):
    st+=str(pre[i][j])
    if(j!=3):
      st+=","
  print(st)

quit
exit


# In[34]:


print(df['home_team'].value_counts())



# In[35]:


dicts = {}
j = 0
for i in teams:
        dicts[i] = j
        j=j+1


# In[36]:


print(dicts)


# In[37]:


rows, cols = (27,27) 
arr = [[0 for i in range(cols)] for j in range(rows)] 
# print(arr)
arr1 = [[0 for i in range(cols)] for j in range(rows)] 
print(arr1)


# In[38]:


for ind in df.index:
#   print(dicts[df['home_team'][ind]])
#   print(dicts[df['away_team'][ind]])
  if df['result'][ind]=='A' :
    arr[dicts[df['home_team'][ind]]][dicts[df['away_team'][ind]]] += 1
  elif df['result'][ind]=='H' :
    arr[dicts[df['away_team'][ind]]][dicts[df['home_team'][ind]]] += 1
  else :
    arr[dicts[df['home_team'][ind]]][dicts[df['away_team'][ind]]] += 0.5
    arr[dicts[df['away_team'][ind]]][dicts[df['home_team'][ind]]] += 0.5







# In[39]:


# In[40]:

for i in range(len(arr)):
  for j in range(len(arr[0])):
    arr[i][j] = int(arr[i][j])

            
print(arr)

