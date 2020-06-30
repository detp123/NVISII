# ViSII - A VIrtual Scene Imaging Interface

![ViSII domain randomization example](https://i.imgur.com/iZrMLuo.png)
![ViSII simple scene example](https://i.imgur.com/z4mamZv.png)

ViSII is a python based ray tracer render built on top of NVIDIA OptiX. 
The tool allows you to define complex scenes: 3d meshes, object materials, lights, loading textures, _etc._, and render 
them using ray tracing techniques. 
ViSII can be used to export metadata about the scene, _e.g._, object segmentation. 


<!--
This library provides a simple, primarily python-user targeted, interface to rendering images of a virtual scene. Its key cornerstones are:

a) a relatively simple, RTX/OptiX-accelerated path tracer, and
b) a interface (available in both python and C) for declaring a scene, doing basic modifications to it, and rendering images

 The two primary goals of this lirary are
a) ease of use (in particular, for non-expert users, and from languages like python), and
b) ease of deployment (ie, allowing headless rendering, minimal dependenies, etc).
To be clear: There will be more sophisitcated renderers out there, as well as faster ones, better ones, etc;
the goal of _this_ project is to offer something that's easy to get started with.
 -->
## Installing

We highly recommend hat you used the pre-built wheels for python as follow: 
```
pip install visii
```
Also make sure the latest NVIDIA drivers (R451) are installed as well as at least CUDA 10.2 (or above) installed.  
If you need more information about how to install NVIDIA drivers and CUDA on Ubuntu please consult
[this](https://ingowald.blog/installing-the-latest-nvidia-driver-cuda-and-optix-on-linux-ubuntu-18-04/).
You can 

## Getting Started 

We wrote 10 basic examples covering most of the functionalities of visii, [here](examples/). 
You can also find more extensive documentation [here](https://owl-project.github.io/ViSII/).

## Building 

Information on how to build to be added in near future. 

<!-- Although we do not recommend building visii from scratch. Here are the rudimentary 
requirements: 
-->
## Citation

If you use this tool in a research project, please cite as follows:

    @misc{Morrical20visii,
    author = {Nathan Morrical and Jonathan Tremblay and Stan Birchfield and Ingo Wald},
    note= {\url{ https://github.com/owl-project/ViSII/ }},
    title = {{ViSII}: VIrtual Scene Imaging Interface},
    Year = 2020
    }


<!-- ## Code Structure

- submodules/ : external git submodule dependencies to build this
- visii/ : the (static) library that provides the renderer
    - visii/scene/ : code that maintains the visii "scene graph"
    - visii/render/ : the actual renderer(s) provided in this library
- cAPI/ : a extern "C" shared library/DLL interface for this library
- python/ : python interface for this library
- (?) tools/ : importer tools, as required for samples

## Building

todo

## Samples

todo: need (at least) the following samples

- load an OBJ file, declare camera and light, render an image, save as ppm

- same as before, but do simple omdification of scene (ie, rotate it)

- same as before, but two scene (probably need way of "naming" objects when loading), with one rotating around the other

- same as before, but also render depth, and primID -->
