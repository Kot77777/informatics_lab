import numpy as np
import matplotlib.pyplot as plt

capacity = []
size = []
with open('vector_push_back_capacity_size.txt', 'r', encoding = 'utf8') as f:
    for line in f:
        s = line.rstrip().split(sep = ' ')
        capacity.append(int(s[0]))
        size.append(int(s[1]))
n = np.array([i for i in range(1, 10001)])
np_cap = np.array(capacity)
np_size = np.array(size)

plt.plot(n, np_cap, label = 'capacity от i', color = 'purple')
plt.plot(n, np_size, label = 'size от i', color = 'green')

plt.grid(linewidth = 0.5)

plt.xlabel('i, номер итерации', fontsize=10)
plt.ylabel('размер capacity and size', fontsize=10)
plt.legend()
plt.savefig("График зависимости capacity, size от i", dpi=600)
plt.show()
