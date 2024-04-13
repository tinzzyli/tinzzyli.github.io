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

<div class="row justify-content-center"> <!-- Center the row -->
    <div class="col-sm mt-4 mt-md-1 text-center"> <!-- Center the column content -->
    </div>
    <div class="col-sm mt-4 mt-md-1 text-center" style="width: 80%;"> 
        {% include figure.html path="assets/img/bulletarm_1.png" title="The environment containing a robot arm, a camera, and a workspace (Credit to authors of BulletArm)" class="img-fluid rounded z-depth-1" %}
    </div>
    <div class="col-sm mt-4 mt-md-1 text-center"> <!-- Center the column content -->
    </div>
</div>

<div class="caption">
    The environment containing a robot arm, a camera, and a workspace(Credit to authors of BulletArm).
</div>

DQN takes heightmaps as input and outputs a q value map, it indicates the desired action of the robotic arm(action = [x, y, rotation], x and y are the postion the arm should reach to, rotation is the degree of the end-effector) that the agent should execute. (e.g. The x,y position of the max element on the q value map represents the desired).



<div class="row justify-content-center"> 
    <div class="col-sm mt-4 mt-md-0 text-center" style="width: 80%;"> 
        {% include figure.html path="assets/img/obs_1.png" title="example image of observation" class="img-fluid rounded z-depth-1" style="max-width: 140%; height: auto;" %}
    </div>
    <div class="col-sm mt-4 mt-md-1 text-center"> 
    </div>
    <div class="col-sm mt-4 mt-md-1 text-center"> 
        {% include figure.html path="assets/img/q_map_1.png" title="example image of q value map" class="img-fluid rounded z-depth-1" style="max-width: 140%; height: auto;" %}
    </div>
</div>

<div class="caption">
    An example image of observation(Left), and an example image of q value map(Right).
</div>

Our motivation is to find out the relationship between the initial workspace layout and the agent's successful rate. Unlike other applictions of adversarial attacks that add perturbations on the input image, we aim at searching for a vulnerable layout of the workspace, which increase the failing rate of the agent.

To achieve it, a differentiable renderer should be introduced to replace the original one, thus we used <a href="https://github.com/BachiLi/redner/tree/master">redner</a>, a differentiable renderer that can take the derivatives of rendering outputs with respect to arbitrary scene parameters. This enhancement facilitates direct optimization of the model using backpropagation algorithms.

<div class="row justify-content-center"> 
    <div class="col-sm mt-4 mt-md-1 text-center"> 
        {% include figure.html path="assets/img/bulletarm_2.png" title="example image" class="img-fluid rounded z-depth-1" style="max-width: 140%; height: auto;" %}
    </div>
    <div class="col-sm mt-4 mt-md-1 text-center"> 
        {% include figure.html path="assets/img/bulletarm_3.png" title="example image" class="img-fluid rounded z-depth-1" style="max-width: 140%; height: auto;" %}
    </div>
    <div class="col-sm mt-4 mt-md-1 text-center"> 
        {% include figure.html path="assets/img/bulletarm_4.png" title="example image" class="img-fluid rounded z-depth-1" style="max-width: 140%; height: auto;" %}
    </div>
</div>

<div class="caption">
    The same layout with three different actions suggested by DQN. It is observed that the agent fails, but it is not due to imprecision.
</div>

For the object grasping task investigation, experiments conducted within the Bulletarm robotic framework demonstrated that the effect of a given action on the environment is deterministic. Moreover, it was observed that the boundaries between success and failure within the action space are non-robust.