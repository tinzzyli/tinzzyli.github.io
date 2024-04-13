---
layout: page
title: LLM + OS
description: Design prompts for a LLM-based agent framework intended to operate smartphone application
img: assets/img/appagent_2.png
# redirect: https://unsplash.com
importance: 1
category: Software Engineering
---

This project is based on <a href="https://github.com/mnotgod96/AppAgent">AppAgent</a>, a novel LLM-based multimodal agent framework designed to operate smartphone applications.

<div class="row justify-content-center"> 
    <div class="col-sm mt-4 mt-md-1 text-center"> 
        {% include figure.html path="assets/img/appagent_3.png" title="example image" class="img-fluid rounded z-depth-1" style="max-width: 140%; height: auto;" %}
    </div>
    <div class="col-sm mt-4 mt-md-1 text-center"> 
        {% include figure.html path="assets/img/appagent_4.png" title="example image" class="img-fluid rounded z-depth-1" style="max-width: 140%; height: auto;" %}
    </div>
    <div class="col-sm mt-4 mt-md-1 text-center"> 
        {% include figure.html path="assets/img/appagent_5.png" title="example image" class="img-fluid rounded z-depth-1" style="max-width: 140%; height: auto;" %}
    </div>
</div>

<div class="caption">
    Figures from left to right demonstrates the process of AppAgent operating an smartphone app.
</div>

AppAgent learns to navigate and use new apps, however, it shows weakness when executing complex tasks. We aim at designing a effective prompt and a knowledge base for it to help reduce LLM hallucination.