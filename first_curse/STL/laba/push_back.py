import numpy as np
import matplotlib.pyplot as plt

time = []
time1 = []
with open('vector-push-back.txt', 'r', encoding = 'utf8') as f:
    for line in f:
        time.append(int(line))

with open('subvector_push_back_time.txt', 'r', encoding = 'utf8') as f:
    for line in f:
        time1.append(int(line))

#n = np.array([i for i in range(1, 10001)])
np_time = np.array(time)
np_time1 = np.array(time1)
np_size = np.array([100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000])

t = np.polyfit(np_size, np_time,  1)
f = np.poly1d(t)

t1 = np.polyfit(np_size, np_time1,  2)
f1 = np.poly1d(t1)


plt.plot(np_size, f(np_size),
         linestyle='-', alpha = 1,
         color = "b", ms=3, zorder = 0, label = 'time от size for vector')
plt.scatter(np_size, np_time, color = 'blue', linewidths = 0.05)

plt.plot(np_size, f1(np_size),
         linestyle='-', alpha = 1,
         color = "purple", ms=3, zorder = 0, label = 'time от size for subvector')
plt.scatter(np_size, np_time1, color = 'g', linewidths = 0.05)


plt.grid(linewidth = 0.5)

plt.xlabel('size', fontsize=10)
plt.ylabel('время, нс', fontsize=10)
plt.legend()
plt.savefig("График зависимости реализации push_back для list и subforwardlist от size", dpi=600)
plt.show()

