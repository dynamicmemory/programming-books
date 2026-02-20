import matplotlib.pyplot as plt 
import numpy as np

data = np.arange(10)
# plt.plot(data)
# plt.show()

# fig = plt.figure()
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

# ax = fig.add_subplot()
# data = np.random.standard_normal(40).cumsum()
# ax.plot(data, color="red", linestyle="-", label="default")
# ax.plot(data, color="green", linestyle="--", 
#         drawstyle="steps-post", label="steps-post")
# ax.legend()

# ax.plot(np.random.standard_normal(1000).cumsum());
# ticks = ax.set_xticks([0,250,500,750,1000])
# labels = ax.set_xticklabels(["one", "two", "three", "four", "five"], rotation=30,
#                             fontsize=8)
# ax.set_xlabel("Stages")
# ax.set_title("My first matplotlib plot")


# ax.plot(np.random.randn(1000).cumsum(), color="black", label="one")
# ax.plot(np.random.randn(1000).cumsum(), color="black", linestyle="dashed", label="two")
# ax.plot(np.random.randn(1000).cumsum(), color="black", linestyle="dotted", label="three")
# ax.legend()

from datetime import datetime 
import pandas as pd 

# fig, ax = plt.subplots()
#
# data = pd.read_csv("./examples/spx.csv", index_col=0, parse_dates=True)
# spx = data["SPX"]
#
# spx.plot(ax=ax, color="green")
#
# crisis_data = [
#         (datetime(2007, 10, 11), "Peak of bull market"),
#         (datetime(2008, 3, 12), "Bear Stearns Fails"),
#         (datetime(2008, 9, 15), "Lehman Bankruptcy")
#         ]
#
# for date, label in crisis_data:
#     ax.annotate(label, xy=(date, spx.asof(date) + 75),
#                 xytext=(date, spx.asof(date) + 225),
#                 arrowprops=dict(facecolor="black", headwidth=4, width=2, headlength=4),
#                 horizontalalignment="left", verticalalignment="top")
#
# ax.set_xlim(["1/1/2007", "1/1/2011"])
# ax.set_ylim([600,1800])


# s = pd.Series(np.random.standard_normal(10).cumsum(), index=np.arange(0, 100, 10))
# s.plot()

# df = pd.DataFrame(np.random.standard_normal((10,4)).cumsum(0),
#                   columns=["A","B","C","D"], index=np.arange(0, 100, 10))
# plt.style.use("grayscale")
# df.plot()

# fig, axes = plt.subplots(2,1)
# data = pd.Series(np.random.uniform(size=16), index=list("abcdefghijklmnop"))

# data.plot.bar(ax=axes[0], color="blue", alpha=0.4)
# data.plot.barh(ax=axes[1], color="blue", alpha=0.4)

# df = pd.DataFrame(np.random.uniform(size=(6,4)), index=["one", "two", "three", "four", "five", "six"],
#                   columns=pd.Index(["A", "b", "C", "D"], name="Genus"))
# df.plot.bar()

df.plot.barh(stacked=True, alpha=0.5)


plt.show()
