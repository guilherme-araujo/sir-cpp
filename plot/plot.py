import seaborn as sns
import sys
import csv
from statistics import stdev
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.ticker as mtick

pd.set_option('display.max_rows', None)

results = []
with open('sample-out.txt') as csv_file_r:
    csv_reader = csv.reader(csv_file_r, delimiter=';')
    qtss = []
    qtis = []
    qtrs = []
    
    for row in csv_reader:
        if(row[0]=='shistory'):
            qts = int(row[3])
            qti = int(row[4])
            qtr = int(row[5])
            cyc = int(row[2])
            results.append([cyc, qts, 'Susceptible'])
            results.append([cyc, qti, 'Infected'])
            results.append([cyc, qtr, 'Recovered'])

df = pd.DataFrame(results, columns=['cyc', 'qtd', 'type'])


fig = sns.lineplot(data=df, x="cyc", y="qtd", hue="type")

#plt.legend(bbox_to_anchor=(1.05, 1.0), loc='upper left')

#plt.tight_layout()
#ax.set(xlabel="α", ylabel="Fixation %" )
#plt.setp(ax.get_xticklabels(), rotation=90, horizontalalignment='center')

plt.show()
