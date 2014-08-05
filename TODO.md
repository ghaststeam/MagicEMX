TODO:
=

1. Emulate the CPU*
1. Emulate the GPU*
The PS4's GPU is a slightly custom Radeon GCN 7870, which houses VGT (Vertex Grouper & Tessellator) Registers, Primitive Assembly Registers, General Shader Registers, Shader Program Registers, SPI (Serial Peripheral Interface) Registers, Compute Registers, Tiling Registers, Texture Pipe Registers, Depth Buffer Registers, Color Buffer Registers, and Surface Synchronization Registers. All readable/writable registers can be found here: [http://amd-dev.wpengine.netdna-cdn.com/wordpress/media/2013/10/SI_3D_registers.pdf](http://amd-dev.wpengine.netdna-cdn.com/wordpress/media/2013/10/SI_3D_registers.pdf). An entire, comprehensive overview of the Southern Islands I.S.A. can be seen here: [http://developer.amd.com/wordpress/media/2012/12/AMD_Southern_Islands_Instruction_Set_Architecture.pdf](http://developer.amd.com/wordpress/media/2012/12/AMD_Southern_Islands_Instruction_Set_Architecture.pdf). The only know differences between PS4's GPU and a typical Radeon 7870 brand name are mentioned here: [http://en.wikipedia.org/wiki/PlayStation_4_technical_specifications#Graphics_processing_unit](http://en.wikipedia.org/wiki/PlayStation_4_technical_specifications#Graphics_processing_unit).
1. Emulate the RAM*
8 GB GDDR5 (shared with AMD Jaguar CPU & the GPU); 256 MiB of RAM for the MediaCon. 
1. Emulate the MediaCon*
1. Emulate the hard drive*
1. Emulate the flash*
1. Emulate OrbisOS (based on FreeBSD and NetBSD)*
1. Emulate input devices (DirectInput and XInput)
1. Emulate a display (DirectX, OpenGL, Mantle (maybe)
1. Emulate sound (DirectSound, XAudio, Mantle (maybe)
[http://en.wikipedia.org/wiki/AMD_TrueAudio](AMD TrueAudio): Can't find nothing about this without an [en.wikipedia.org/wiki/Non-disclosure_agreement](NDA).
1. Emulate Blu-Ray drive (also implement using ISO images, or the loading of other file types)
1. Implement common emulation/virtualization features (save states, recording, rapid fire, custom controls, etc.)
1. Implement a debugger, disassembler, memory editor, etc. (to make reversing easier through the emulator)
1. Implement extra nice to have features (higher resolutions, frame rate cap removal, NTSC/PAL conversion, english translations, aspect ratio patching, etc.)

*NOTE: These will require more research.


All of these things are subject to change, however in general they can be implemented as well as anything.


The only really difficult thing I can think of is rewind. For people who don't know, rewind is basically being able to emulate a console backwards as well as forwards. In other words, it's twice as much work for the hardware you are running, and often times makes things break, crash, freeze, or cause other problems. There are very few emulators which have this feature for this reason.

However, a programmer created a reverse emulation library, and it seems to work fine enough that multiple Android emulators use it, but mostly it is used to emulate very old systems and it is very buggy. But who knows, maybe because it is PC like it will be easier than we think. We will have to see.

:-) Please contribute anything you can! If you wish to donate, donations can be sent here: [http://www.ps4hacking.wordpress.com](http://www.ps4hacking.wordpress.com)
=
