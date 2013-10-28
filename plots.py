import numpy as np
import matplotlib.pyplot as mplt
import sys, string, os
from StringIO import StringIO

def DoPlots (Filename, i):
    """
    Do plots of the data taken by argument
    in: string filename, the name of the file
    int i, the number of the plot
    """
    data = np.loadtxt(Filename)
    x = data[:,1]
    y = data[:,2]
    mplt.scatter(x, y)
    mplt.xlabel('Kpc')
    mplt.ylabel('Kpc')
    mplt.title(str(i*1)+'*10^9 yr')
    mplt.show()

if (len(sys.argv) < 2):
    print "This program needs at least 1 data for plotting"
    exit

for i in range (len(sys.argv)):
    if i != 0:
        name = sys.argv[i]
        DoPlots (name, i)

    
    


    
  
