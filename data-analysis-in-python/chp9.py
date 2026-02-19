import matplotlib.pyplot as plt 
import numpy as np

data = np.arange(10)
# plt.plot(data)
# plt.show()

fig = plt.figure()
# ax1 = fig.add_subplot(2,2,1)
# ax2 = fig.add_subplot(2,2,2)
# ax3 = fig.add_subplot(2,2,3)
# ax4 = fig.add_subplot(2,2,4)
#
# ax1.hist(np.random.standard_normal(500), bins=20,
#          color="black", alpha=0.5)
# ax2.scatter(np.arange(10), np.arange(10) + np.random.standard_normal(10))
# ax3.plot(np.random.standard_normal(50).cumsum(), 
#          color="black", linestyle="dashed")

# fig, axes = plt.subplots(2,2,sharex=True, sharey=True)
# for i in range(2):
    # for j in range(2):
    #     axes[i, j].hist(np.random.standard_normal(500), bins=10, color="black", alpha=0.5)
# fig.subplots_adjust(wspace=0, hspace=0)

# ax =fig.add_subplot()
# ax.plot(np.random.standard_normal(50).cumsum(), 
        # color="green", 
        # linestyle="--",
        # marker="*")

ax = fig.add_subplot()
data = np.random.standard_normal(40).cumsum()
ax.plot(data, color="red", linestyle="-", label="default")
ax.plot(data, color="green", linestyle="--", 
        drawstyle="steps-post", label="steps-post")
ax.legend()

plt.show()
