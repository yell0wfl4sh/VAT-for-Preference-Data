
# coding: utf-8

# In[78]:


import pandas as pd


# In[79]:


df=pd.read_csv('laligadataset.csv')


# In[80]:


df.head()


# In[81]:


df = df.iloc[27043:]
df.head()


# In[82]:


df = df[df.division != 2]
df


# In[83]:


a = ['Recreativo de Huelva','Las Palmas','Alaves','Elche','Leganes','Gimnastic de Tarragona','Murcia','Cordoba','Xerez','Girona','Tenerife','Numancia','Hercules']
df = df[~df['localTeam'].isin(a)]
df = df[~df['visitorTeam'].isin(a)]
# desired_indices = [i for i in len(df.index) if i not in unwanted_indices]
# desired_df = df.iloc[desired_indices]


# In[84]:


teams = df['localTeam'].unique()
print(teams)
df['localTeam'].nunique()


# In[85]:


df.head()


# In[86]:


df['localTeam'].value_counts()


# In[87]:


df['visitorTeam'].value_counts()


# In[88]:


dicts = {}
j = 0
for i in teams:
        dicts[i] = j
        j=j+1


# In[89]:


print(dicts)


# In[90]:


rows, cols = (25, 25) 
arr = [[0 for i in range(cols)] for j in range(rows)] 
# print(arr)
arr1 = [[0 for i in range(cols)] for j in range(rows)] 
print(arr1)


# In[91]:


for ind in df.index:

  if df['localGoals'][ind]<df['visitorGoals'][ind] :
    arr[dicts[df['localTeam'][ind]]][dicts[df['visitorTeam'][ind]]] += 1
  elif df['localGoals'][ind]>df['visitorGoals'][ind] :
    arr[dicts[df['visitorTeam'][ind]]][dicts[df['localTeam'][ind]]] += 1
  else :
    arr[dicts[df['localTeam'][ind]]][dicts[df['visitorTeam'][ind]]] += 0.5
    arr[dicts[df['visitorTeam'][ind]]][dicts[df['localTeam'][ind]]] += 0.5

for i in range(len(arr)):
	for j in range(len(arr[0])):
		arr[i][j] = int(arr[i][j])

print(arr)
