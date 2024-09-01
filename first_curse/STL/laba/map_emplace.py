import numpy as np
import matplotlib.pyplot as plt

time = []
with open('map-emplace.txt', 'r', encoding = 'utf8') as f:
    for line in f:
        time.append(int(line))

np_time = np.array(time)
np_size = np.array([100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000])

t = np.polyfit(np_size, np_time,  1)
f = np.poly1d(t)

plt.plot(np_size, f(np_size),
         linestyle='-', alpha = 1,
         color = "b", ms=3, zorder = 0, label = 'time от size for map')
plt.scatter(np_size, np_time, color = 'purple', linewidths = 0.05)

plt.grid(linewidth = 0.5)

plt.xlabel('size', fontsize=10)
plt.ylabel('время, нс', fontsize=10)
plt.legend()
plt.savefig("График зависимости реализации emplace для map от size", dpi=600)
plt.show()

