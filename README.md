# OpenGL Wrapper and Library
This library is about reinventing the wheel. If you're looking for the best OpenGL wrapper or library, you're in the wrong place. There are probably a lot of better library out there.

This is my custom library to ease myself using OpenGL. This library is based on GLEW library and use C++ as it's language.

## Build
### What you need
- [Git](https://git-scm.com/downloads)
- [CMake](https://cmake.org/download/)
- Windows
	- MSVC/MinGW

First, clone GLWL repo

`git clone https://github.com/Greffin28/GLWL`

Next, we need to download GLEW from either the [SourceForge](http://glew.sourceforge.net/) website or from the [GitHub Releases](https://github.com/nigels-com/glew/releases). I'll be building from source (source files already provided). If you download the binaries instead, you can skip a few steps ahead. You can also clone the repo or download the source code and build the source and the library yourself, but i won't go there.

Make sure, there is a folder called `include` and there are 3 source files in `ext_lib/glew/src` folder. If those folder or files doesn't exist, that means you downloaded the wrong file, try another. Now, extract them to a new folder called `ext_lib` inside the `GLWL` folder so it would look like `/GLWL/ext_lib/glew-x.x.x`. Then, rename the folder from `glew-x.x.x` to `glew`.

### Windows
#### MSVC
##### Building GLEW
Now, go to `ext_lib/glew/build/vc12` which will contain the Visual Studio solution for VS. If you use higher VS version than the solution, just click OK later when asked to upgrade. When it's opened, change the Solution Configuration from Debug to Release. Then press `CTRL+SHIFT+B` to start the build process.
##### Building GLWL
Next, go back to `GLWL` folder. Make a new folder called `build` then open it, this is optional. From there, run `cmake ..` (provided that your default compiler is MSVC). After it run successfully, open up the GLWL solution and press `CTRL+SHIFT+B`. The files will be in `lib` folder.

