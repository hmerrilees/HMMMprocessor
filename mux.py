import matplotlib.pyplot as plt
import matplotlib
import numpy as np
from matplotlib.animation import FuncAnimation

# Define colors for inputs and output
input_color_1 = "red"
input_color_2 = "blue"
output_color = "black"

duration = 10  # seconds
fps = 1 

num_frames = int(duration * fps)

def animate(i):
    select_value = i % 2

    if select_value:
        input_color_active = input_color_1
        input_color_inactive = input_color_2
        select_label = "1"
        output_label = "a"
    else:
        input_color_active = input_color_2
        input_color_inactive = input_color_1
        select_label = "0"
        output_label = "b"

    ax.clear()

    # Draw multiplexer shape
    x_vals = [-.25, -.25, .25, .25]
    y_vals = [-0.75, 0.75, 0.5, -0.5]
    ax.add_patch(matplotlib.patches.Polygon(xy=list(zip(x_vals, y_vals)), color="black"))

    # Draw input lines
    ax.plot([-.9, -.25], [0.5, 0.5], color=input_color_1, linewidth=3)
    ax.plot([-.9, -.25], [-0.5, -0.5], color=input_color_2, linewidth=3)

    # Draw output line
    ax.plot([.25, .9], [0, 0], color=input_color_active, linewidth=3)
    # Draw select signal indicator
    ax.plot([0, 0], [.8, 0.65], color="black", linewidth=2)

    # Set axis limits
    ax.set_xlim([-1.2, 1.2])
    ax.set_ylim([-1.2, 1.2])

    # Set labels
    ax.text(-1, 0.5, "a", fontsize=20, color="black", ha="center", va="center")
    ax.text(-.35, 0.6, "1", fontsize=20, color="black", ha="center", va="center")
    ax.text(-1, -0.5, "b", fontsize=20, color="black", ha="center", va="center")
    ax.text(-.35, -0.4, "0", fontsize=20, color="black", ha="center", va="center")
    ax.text(.05, .9, f"select: {select_label}", fontsize=20, color="black", ha="right", va="center")
    ax.text(1, 0, output_label, fontsize=20, color="black", ha="center", va="center")

    # Set title
    title = f"Multiplexer Animation (Frame {i + 1}/{num_frames})"
    ax.set_title(title)

fig, ax = plt.subplots()

animation = FuncAnimation(fig, animate, frames=num_frames, interval=1000 / fps)
plt.show()
