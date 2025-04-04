#!/usr/bin/env python
# coding: utf-8

# # ***数据集进行的 探索性数据分析（EDA），涵盖分布特征、集中趋势、离散程度和数据质量的完整分析***

# # **预处理**

# ## **读取Excel文件**

# In[1]:


import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from scipy import stats
import os

# 读取Excel文件
# file_path = "trainingData.xlsx"
import os
file_path = os.path.join(os.path.dirname(__file__), "trainingData.xlsx")
df = pd.read_excel(file_path, engine='openpyxl')  # 使用openpyxl引擎

# 查看前5行数据
print(df.head())


# ## **全局设置中文字体**

# In[2]:


# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']  # Windows系统
# plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']  # Mac系统
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示为方框的问题


# # **1. 数据分布特征（偏态与峰态）**
# 使用 `scipy.stats` 计算偏态（Skewness）和峰态（Kurtosis）：

# In[3]:


numeric_cols = df.select_dtypes(include=['float64', 'int64']).columns
for col in numeric_cols:
    skewness = stats.skew(df[col])
    kurtosis = stats.kurtosis(df[col])
    print(f"{col}: 偏态 = {skewness:.2f}, 峰态 = {kurtosis:.2f}")


# ## 单变量分布可视化（直方图 + 密度曲线 + 偏态/峰态标注）

# In[4]:


# 设置画布
plt.figure(figsize=(14, 10))

numeric_cols = df.select_dtypes(include=['float64', 'int64']).columns
# numeric_cols 是通过 df.select_dtypes(include=['float64', 'int64']) 筛选出的数值型列名列表。
# 确保只对数值列计算统计量。

for i, col in enumerate(numeric_cols, 1):
    plt.subplot(3, 3, i)
    # 绘制直方图与密度曲线
    sns.histplot(df[col], kde=True, color='skyblue', bins=15)
    # 计算偏态和峰态
    skewness = stats.skew(df[col])
    kurtosis = stats.kurtosis(df[col])
    # 添加标题和标注
    plt.title(f"{col}\n偏态 = {skewness:.2f}, 峰态 = {kurtosis:.2f}", fontsize=10)
    plt.xlabel('')
    plt.ylabel('频数')

plt.tight_layout()
plt.show()


# **示例结论：**  
# - **对称性**：大部分数值列偏态接近0，说明分布基本对称。  
# - **峰态**：峰态值均为负（除`***`外），表明数据分布比正态分布更平坦（低峰态）。  
# - **命中概率**：轻微左偏（偏态=-0.29），可能存在少数低概率异常值。

# # **2. 集中趋势（均值、中位数、众数）**

# In[5]:


central_tendency = df[numeric_cols].agg(['mean', 'median', lambda x: x.mode()[0]])
central_tendency.rename(index={'<lambda>': 'mode'}, inplace=True)
print(central_tendency)


# **示例输出结果：**
# |         | 掉落速度 | 转速 | 扫描角 | 作用距离 | 散布误差 | 环境风速 | 命中概率 |
# |---------|---------|------|--------|----------|----------|----------|----------|
# | mean    | 10.0    | 3.75 | 30.0   | 120.0    | 0.3      | 4.0      | 0.402    |
# | median  | 10.0    | 3.75 | 30.0   | 120.0    | 0.3      | 4.0      | 0.376    |
# | mode    | 8.0     | 3.0  | 26.0   | 100.0    | 0.1      | 0.0      | 0.529    |
# 
# **示例结论：**  
# - **均值 = 中位数**：如`掉落速度`、`转速`等，说明数据分布对称。  
# - **众数差异**：例如`命中概率`的众数（0.529）与均值（0.402）不同，表明可能存在多峰分布。

# # **3. 离散程度（标准差、四分位距、极差）**

#  **关键统计量意义**
# | 统计量 | 公式/解释                     | 用途                     |
# |--------|-----------------------------|--------------------------|
# | std    | $\sqrt{\frac{\sum (x_i - \bar{x})^2}{n}}$ | 数据波动大小（单位同原始数据） |
# | var    | $\frac{\sum (x_i - \bar{x})^2}{n}$       | 数据离散程度（平方单位）     |
# | IQR    | $Q3 - Q1$                   | 抗异常值，反映数据集中趋势   |
# | max    | $\max(x)$                   | 数据上限                 |
# | min    | $\min(x)$                   | 数据下限                 |

# In[6]:


dispersion = df[numeric_cols].agg(['std', 'var', lambda x: x.quantile(0.75) - x.quantile(0.25), 'max', 'min'])
# 自定义函数 lambda x: x.quantile(0.75) - x.quantile(0.25)
# 计算 四分位距 (IQR) = 上四分位数 (Q3) - 下四分位数 (Q1)，反映中间50%数据的离散程度。

dispersion.rename(index={'<lambda>': 'IQR'}, inplace=True)
# 将匿名函数 lambda 生成的默认行名 '<lambda>' 改为更具可读性的 'IQR'。inplace=True 表示直接修改原对象，不创建新对象。

print(dispersion)


# **示例输出结果：**
# |       | 掉落速度 | 转速 | 扫描角 | 作用距离 | 散布误差 | 环境风速 | 命中概率 |
# |-------|---------|------|--------|----------|----------|----------|----------|
# | std   | 1.41    | 0.56 | 2.83   | 14.14    | 0.16     | 2.83     | 0.22     |
# | IQR   | 2.0     | 1.0  | 4.0    | 20.0     | 0.2      | 4.0      | 0.34     |
# | max   | 12.0    | 4.5  | 34.0   | 140.0    | 0.5      | 8.0      | 0.739    |
# | min   | 8.0     · | 3.0  | 26.0   | 100.0    | 0.1      | 0.0      | 0.076    |
# 
# **示例结论：**  
# - **低离散度**：如`转速`（标准差=0.56），数据集中。  
# - **高离散度**：如`作用距离`（标准差=14.14），数据波动较大。  
# - **异常值风险**：`命中概率`的极差（0.076~0.739）较大，需进一步检查。

# # **4.数据一致性验证**
# 检查数值范围是否合理：

# ## **4.1. 基础验证（数值范围与逻辑）**
# ### **验证数值是否在合理范围内**

# In[7]:


def validate_ranges(df):
    rules = {
        '掉落速度': (8, 12),      # 应介于8~12
        '转速': (3, 4.5),        # 应介于3~4.5
        '命中概率': (0, 1),       # 应在0~1之间
        '环境风速': (0, 8)        # 应介于0~8
    }
    
    violations = {}
    for col, (min_val, max_val) in rules.items():
        invalid = df[~df[col].between(min_val, max_val)]
        if not invalid.empty:
            violations[col] = invalid[[col]].to_dict()
    
    return violations

# 执行验证
range_violations = validate_ranges(df)
print("超出范围的数据：\n", range_violations)


# **输出说明**：  
# - 返回空字典 `{}` 表示所有数据符合范围。  
# - 若有违规数据，会显示具体列和违规值。

# ## **4.2. 业务逻辑验证**
# ### **验证字段间逻辑关系**

# In[8]:


# 例如：*当环境风速>6时，命中概率应<0.5*（假设业务规则）

logic_violations = df[(df['环境风速'] > 6) & (df['命中概率'] >= 0.5)]
if not logic_violations.empty:
    print("违反业务逻辑的数据：\n", logic_violations[['环境风速', '命中概率']])
else:
    print("业务逻辑验证通过")


# ## **4.3. 唯一性验证**
# ### **检查样本编号是否唯一**

# In[9]:


if df['样本编号'].duplicated().any():
    print("存在重复的样本编号！")
else:
    print("样本编号唯一性验证通过")


# ## **4.4. 数据类型验证**

# In[10]:


print("各列数据类型：\n", df.dtypes)
# 确保数值列不为 `object` 类型（避免混入文本）。


# ## **4.5. 缺失值检测**

# In[11]:


print("缺失值统计：\n", df.isnull().sum())
# 若存在缺失值，需处理：删除 (`df.dropna()`) 或填充 (`df.fillna(...)`)。


# ## **4.6. 高级验证（统计分布一致性）**
# ### **检查同一分组内数据波动是否合理**

# In[12]:


# 例如：*同一转速下的命中概率标准差应<0.2*
group_std = df.groupby('转速')['命中概率'].std()
if (group_std > 0.2).any():
    print("异常波动分组：\n", group_std[group_std > 0.2])


# ## **4.7. 可视化验证**
# ### **箱线图检测异常值**

# In[13]:


import seaborn as sns
sns.boxplot(data=df[numeric_cols], orient='h')
plt.title('数值分布箱线图')
plt.show()
# 箱体外点即为潜在异常值。


# ### **散点图验证逻辑关系**

# In[14]:


sns.scatterplot(data=df, x='环境风速', y='命中概率', hue='转速')
plt.axhline(y=0.5, color='red', linestyle='--')  # 标记阈值
plt.title('环境风速 vs 命中概率')
plt.show()


# # **可视化补充**
# ## **直方图（分布检查）**

# In[15]:


df[numeric_cols].hist(bins=10, figsize=(12, 8))
plt.tight_layout()
plt.show()


# # **箱线图（异常值检测）**

# In[16]:


df[numeric_cols].plot(kind='box', subplots=True, figsize=(12, 6))
plt.tight_layout()
plt.show()


