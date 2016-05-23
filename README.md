# Raytracer-2

![alt tag](./onyx_blur_close.png)

Requires Liblapin 1.8 (from Jason Brillante) in order for it to work !

Very interesting project, we had to create a 3d render application taking its scene sources from .ini files.

This project is the second version of the Raytracer.

## Features

Figures : sphere, plane, cone, cylinder, cube

light : yes

shadows : yes

reflection: yes

refraction: yes

distance focus: yes

export in .ini: yes

export in .png: yes

multi-thread: yes

This second version of the raytracer know works with two windows, one for the render, the second one for the menu.
From the menu you can access to every object from the scene, modify them, delete theme or even add new ones to your scene.
The menu also allows selecting wihich effect you would like to turn on or off, saving your work and chosing the number of threads you would like to use for rendering.

## Usage

Just run
```
make
```

and
```
./raytracer1 file_name
```

or 

```
./raytracer2
```

and build your own scene file !

you can find scene files in the scenes folder.
