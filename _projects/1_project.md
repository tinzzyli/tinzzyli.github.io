---
layout: page
title: Robotic Arm Testing
description: Apply adversarial attacks on a robotic arm
img: assets/img/pybullet_1.png
importance: 1
category: Software Engineering
---

This project is elaborated based on an open-sourced benchmark and learning-environment
for robotic manipulation: <a href="https://github.com/ColinKohler/BulletArm">BulletArm</a>.  BulletArm builds upon <a href="https://pybullet.org/wordpress/">PyBullet</a>, providing a diverse set of tools tailored to robotic manipulation simulations.

In BulletArm, a visual-based agent is used to interact with the environment. BulletArm uses a non-differentiable renderer to obtain heightmaps from the workspace as the observation of the environment.

<div class="row justify-content-center " style="width: 40%;"> <!-- Center the row -->
    <div class="col-sm mt-12 mt-md-0 text-center" > <!-- Center the column content -->
        {% include figure.html path="assets/img/bulletarm_1.png" title="The environment containing a robot arm, a camera, and a workspace (Credit to authors of BulletArm)" class="img-fluid rounded z-depth-1" style="width: 50%;"}
    </div>
</div>

<div class="caption">
    The environment containing a robot arm, a camera, and a workspace (Credit to authors of BulletArm)
</div>

DQN takes heightmaps as input and outputs a q value map, it indicates the desired action of the robotic arm(action = [x, y, rotation], x and y are the postion the arm should reach to, rotation is the degree of the end-effector) that the agent should execute. (e.g. The x, y position of the max element on the q value map represents the desired )

<div class="row justify-content-center">
    <div class="col-sm mt-6 mt-md-0 text-center">
        {% include figure.html path="assets/img/obs_1.png" title="example image of observation" class="img-fluid rounded z-depth-1" style="max-width: 140%; height: auto;" %}
    </div>
    <div class="col-sm mt-6 mt-md-0 text-center">
        {% include figure.html path="assets/img/q_map_1.png" title="example image of q value map" class="img-fluid rounded z-depth-1" style="max-width: 140%; height: auto;" %}
    </div>
</div>

<div class="caption">
    An example image of observation(Left), and an example image of q value map(Right).
</div>

Our motivation is to find out that is there exist a vulnerable layout of the workspace, which increase the failing rate of the agent. Unlike other applictions of adversarial attacks, we aim at  


<div class="row justify-content-sm-center">
    <div class="col-sm-8 mt-3 mt-md-0">
        {% include figure.html path="assets/img/6.jpg" title="example image" class="img-fluid rounded z-depth-1" style="width: 150%; margin: 0 auto;" %}
    </div>
    <div class="col-sm-4 mt-3 mt-md-0">
        {% include figure.html path="assets/img/11.jpg" title="example image" class="img-fluid rounded z-depth-1" style="width: 150%; margin: 0 auto;" %}
    </div>
</div>
<div class="caption">
    You can also have artistically styled 2/3 + 1/3 images, like these.
</div>


The code is simple.
Just wrap your images with `<div class="col-sm">` and place them inside `<div class="row">` (read more about the <a href="https://getbootstrap.com/docs/4.4/layout/grid/">Bootstrap Grid</a> system).
To make images responsive, add `img-fluid` class to each; for rounded corners and shadows use `rounded` and `z-depth-1` classes.
Here's the code for the last row of images above:

{% raw %}
```html
<div class="row justify-content-sm-center">
    <div class="col-sm-8 mt-3 mt-md-0">
        {% include figure.html path="assets/img/6.jpg" title="example image" class="img-fluid rounded z-depth-1" %}
    </div>
    <div class="col-sm-4 mt-3 mt-md-0">
        {% include figure.html path="assets/img/11.jpg" title="example image" class="img-fluid rounded z-depth-1" %}
    </div>
</div>
```
{% endraw %}
