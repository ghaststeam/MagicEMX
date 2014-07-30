PS4EMX
======

The first ever PlayStation 4 emulation/virtualization project!

PS4EMX is a project to create a PS4 emulator/virtual machine that can run on Windows, and later additional operating systems and platforms. Some of the features that will likely be implemented in the future:

1. Supports emulation mode and full virtualization mode.

2. Ability to map emulated memory to secondary-storage, so computers will little RAM can still replicate PS4 RAM in emulation mode.

3. Dynamic recompiler for PS4 shader code to native shader code on the target GPU.

4. The ability to compile a PS4 game to an almost exact native binary with some intermediate code for the target OS, with little software compatibility layers needed to support some code peculiarities.

5. Run Orbis OS and PS4 games alongside Windows and other operating systems.

List of emulated PS4 hardware (eventually):
======

1. 8-core AMD 64-bit "Jaguar" CPU (dual quad-core x86 architecture AMD CPU's)
2. 20 AMD GCN (Graphics Core Next) cores, plus one additional core (more research required)
3. 8GB shared GDDR5 RAM (exact memory allocations research required)
4. Custom Marvell ASIC (unofficially called the MediaCon) which handles H.264 encoding, network background downloads, and other tasks (more research required)
5. Emulation of PS4 hard drive
6. Emulation of PS4 flash chips (more research required)
7. Emulation of networking and PSN/SEN
8. Emulation of PlayStation peripherals (PS Eye, PS Move, controllers, keyboards, mice, headsets, etc)

FAQs:
======

"What needs to be done?"

Check out our brand spanking new TODO file! Now with 400% more TODO!

"Why is there no code?! Why can't I run all PS4 ISO's on my PC in 4K?!"

Most of the "emulation code" is not committed since emulating the processor is not the major part of the PS4 that we don't have as much information about. The part that really is holding us back is the operating system and the games. The fun thing about this generation of consoles is they are like custom PC hardware with cool things to reverse tucked away on the motherboard. Most of this contains security and anti-piracy/anti-reversing stuff. Which is important to get past so we can eventually get access to important things like the CPU, GPU cores, find out what the ARM co-processor does, etc.

"How can you emulate PS4 if there is currently no way to run homebrew, or a lack of information on the console?

Progress is progress, and any information, source code, documentation, or reverse-engineering is helping that along. The "how" is basically using a PS4 to see how it runs and then translating that into code. All kinds of information is coming out, and considering that every console except the Xbox One and PlayStation 4 have gobs of information on them or have been hacked in various ways, these systems are most interesting to hackers/developers/programmers/dudes/whatever.

"But it's so bare...is this a real effort?"

Yes, but the truth is that without the right tools and time it's not possible for the few people who are working on this project to add much over time. We don't have a PS4 or PS4 games, we can't afford high-end computers with Blu-ray drives right now, and it's pretty much the same issue for other developers (Turtle has a Blu-Ray drive and fairly new PC, but no PS4 or games). If anyone wants to help PS4EMX, the first step would be to have the right access (PS4, PS4 games, good computer with Blu-ray drive, hacking experience) to work on decrypting/decompressing/reversing the game PKG/SELF/ELF/PUP/PBP2 files and such, and disassembling it by sections. If anyone wants to contribute, these are the bare necessities, and having these would speed up and improve the project.

Donations are being accepted here: [http://www.ps4hacking.wordpress.com](http://www.ps4hacking.wordpress.com)
=