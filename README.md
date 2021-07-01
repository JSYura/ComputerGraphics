# Computer Graphics CSC317 _Winter 2021_

Homework Page:
https://github.com/karansher/computer-graphics-csc317.git


![_image courtesy Tim Jeruzalski_](images/bunny-rigid-body.gif)

**LEC5101 6101 7001 7501 9101** Tuesdays 18:00-20:00 on zoom

Prof. [Karan Singh](http://www.dgp.toronto.edu/~karan/)  
karan@dgp.toronto.edu    
Office hours: Tuesdays 17:00-18:00 or by appointment

**Tutorial** Tuesdays 20:00-21:00 on zoom

- [Course Overview](#course-overview)
- [Discussion Board](#discussion-board)
- [Required Textbook](#required-textbook)
- [Reading Schedule](#reading-schedule)
- [Lecture Schedule](#lecture-schedule)
- [Marking Scheme](#marking-scheme)
- [Lateness Policy](#lateness-policy)

## Course Overview

This course introduces the basic concepts and algorithms of computer graphics.
It covers the basic methods needed to model and render 3D objects, including
much of the following: graphics displays, basic optics, line drawing, affine and
perspective transformations, windows and viewports, clipping, visibility,
illumination and reflectance models, radiometry, energy transfer models,
parametric representations, curves and surfaces, texture mapping, graphics
hardware, ray tracing, graphics toolkits, animation systems.

**Prerequisites:** C/C++ Programming, Linear Algebra, Calculus, Numerical
Methods ([course
codes](https://fas.calendar.utoronto.ca/course/csc317h1)).

The student is expected to read background material on the hardware and local
software, and should be comfortable with elementary linear algebra, geometry,
and vector calculus. It is also assumed that the student is comfortable
programming in basic C++.

**_(Strongly)_ Recommended preparation:** Multivariable Calculus

## Discussion Board

Please post your questions about the lectures, readings, and assignment due dates on the
[Quercus discussion
board](https://q.utoronto.ca/courses/196707/discussion_topics). We will monitor
this board and attempt to answer questions as they appear. Near deadlines
responses may take longer, so please start assignments early. If your question
is not being answered, you may ask it again at the tutorial or office hours.

For questions specific to each assignment, please post your questions as a GitHub issue
on the assignment repository.


## Required Textbook

![The Book.](https://www.cs.cornell.edu/~srm/fcg4/K22616_cover-300.jpg)

This class involves  **_required reading_** from:

[_Fundamentals of Computer Graphics, Fourth
Edition_](https://www.cs.cornell.edu/~srm/fcg4/), Steve Marschner, Pete Shirley,
et al. 2015.

Digital e-book are available at [CRC
Press](https://www.crcpress.com/Fundamentals-of-Computer-Graphics-Fourth-Edition/Marschner-Shirley/p/book/9781482229394).

## Reading Schedule

| Week | Topic / Event |
| ---- | :------------ |
| 1    | Raster Images: Chapter 3 [intro slides](https://github.com/karansher/317-lectures/blob/main/lecture0.pdf) ,[raster slides](https://github.com/karansher/317-lectures/blob/main/lecture1.pdf) , [recording]
| 2   | Ray Casting: Sections 4.1-4.4 [raycast slides](https://github.com/karansher/317-lectures/blob/main/lecture2.pdf) , [recording]
| 3   | Ray Tracing: Sections 4.5-4.9 [raytrace slides](https://github.com/karansher/317-lectures/blob/main/lecture3.pdf) ,  [recording]
| 4   | Bounding Volume Hierarchy: Section 12.3 [bounding volume slides](https://github.com/karansher/317-lectures/blob/main/lecture4.pdf) ,
| 5  | Meshes: Section 12.1 & skim Chapter 11 [mesh slides](https://github.com/karansher/317-lectures/blob/main/lecture5.pdf)
| 8  | Shading: Review Chapters 6,7,8.1,8.2 & Read Sections 11.4,11.5 & 17 [transforms and shading slides](https://github.com/karansher/317-lectures/blob/main/lecture6.pdf)
| 9  | Kinematics: Sections 15.1-15.5 & 16.1-16.4 (https://github.com/karansher/317-lectures/blob/main/lecture7.pdf)
| 10  | Mass Spring Systems: Section 16.5 & ["Fast Simulation of Mass-Spring Systems" [Tiantian Liu et al. 2013]](http://graphics.berkeley.edu/papers/Liu-FSM-2013-11/Liu-FSM-2013-11.pdf)(https://github.com/karansher/317-lectures/blob/main/lecture8.pdf)
| 11| Advanced Topics(https://github.com/karansher/317-lectures/blob/main/creative-vis-comm-csc317.pdf)
| 12| Review(https://github.com/karansher/317-lectures/blob/main/lecture-review.pdf)




## Lecture Schedule

| Week | Topic / Event |
| ---- | :------------ |
| 1 (12/01)  | Introduction, Raster Images [Assignment 1 (Raster Images) due 20/01](https://github.com/alecjacobson/computer-graphics-raster-images)
| 2 (19/01)    | Ray Casting [Assignment 2 (Ray Casting) due 27/01](https://github.com/Asmathunofficial/computer-graphics-ray-casting)
| 3 (26/01)   | Ray Tracing [Assignment 3 (Ray Tracing) due 03/02](https://github.com/abhimadan/computer-graphics-ray-tracing)
| 4 (02/02)   | Spatial Structures [Assignment 4 (Boundary Volume Hierarchy) due 10/02](https://github.com/idaho777/computer-graphics-bounding-volume-hierarchy)
| 5  (09/02)  | Meshes [Assignment 5 (Meshes) due 24/02](https://github.com/alecjacobson/computer-graphics-meshes)
| 6 (16/02)   | _Work on Assignment 5_
| 7  (23/02)  | TRansformations and Shading. _Study for exam next week_. 
| **01/03* | Take-home test 24 hours to work on it (15% of grade)
| 8 (02/03)   | Shading [Assignment 6 (GLSL) due 10/03](https://github.com/abhimadan/computer-graphics-shader-pipeline)
| **early March** | Drop date (consider if grade so far is <50%)
| 9  (09/03)  | Animation [Assignment 7 (Kinematics) due 19/03](https://github.com/idaho777/computer-graphics-kinematics)
| 10 (16/03)  | Mass-Springs [Assignment 8 (Mass-springs) due 26/03](https://github.com/abhimadan/computer-graphics-mass-spring-systems)
| 11 (23/03)  | Advanced Topics[Final Image/Animation/Game Competition due 3/04]
| **3-5/03** | Take-home test (20% of grade)
| 12 (06/04)  | Advanced Topics 🏆 Showcase 🏆 

[Academic Honesty (required reading)](#academic-honesty)

![_image courtesy Gavin Barill (class of 2017)_](images/gavin-barill-snowglobe.jpg)

## Marking Scheme

| % | Item |
| ----: | :-------------- |
| 1% | Pre-test & survey |
| 8% | Assignment 1 | 
| 8% | Assignment 2 | 
| 8% | Assignment 3 | 
| 8% | Assignment 4 | 
| 15% | Take-home test 1 |
| 8% | Assignment 5 | 
| 8% | Assignment 6 | 
| 8% | Assignment 7 | 
| 8% | Assignment 8 | 
| 20% | Take-home test 2 |

