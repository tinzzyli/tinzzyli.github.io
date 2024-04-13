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

DQN takes heightmaps as input and outputs a q value map, it indicates the desired action of the robotic arm(action = [x, y, rotation], x and y are the postion the arm should reach to, rotation is the degree of the end-effector) that the agent should execute. (e.g. The x,y position of the max element on the q value map represents the desired).

Our motivation is to find out the relationship between the initial workspace layout and the agent's successful rate. Unlike other applictions of adversarial attacks that add perturbations on the input image, we aim at searching for a vulnerable layout of the workspace, which increase the failing rate of the agent.