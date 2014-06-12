PS4EMX
======

PS4EMX - The first ever Playstation 4 emulation/virtualization project!

PS4EMX is a project to create a PS4 emulator/virtual machine that can run on Windows, and any other OSes. Some of the features that will likely be implemented in the future:

1.Supports emulation mode (which emulates the entire x86-64/AMD64 processor and memory, hardware, interrupts, etc., including relevant PS4 hardware), and hopefully one-day full virtualization mode (which will also use some emulation, but will be like VirtualBox for the most part).

2.Ability to map emulated memory to secondary-storage, so computers will little RAM can still replicate PS4 RAM in emulation mode.

3.Dynamic recompiler for PS4 shader code to native shader code on the target GPU.

4.A.O.T. compilation for I.L., which is the ability to compile a PS4 game to an almost exact native binary (with some intermediate code) for the target OS, with little software compatibility layers needed to support some code peculiarities.

5.Run Orbis OS and PS4 games alongside Windows and other OSes (some day)!

A few F.A.Q.s.:
======

"Why is there no emulation code?"

A lot of "emulation code" is not committed since emulating the processor is not the problem with emulating PS4 altogether. And adding emulation code now or in ten years wouldn't make a difference since emulating the processor is not holding the project back, and adding emulation code for the processor won't suddenly give you a PS4 emulator either since it's more complex than that.

"How can you emulate PS4 when there's no homebrew and no documentation on GPU, etc., etc.?"

You can and you can't -- that's basically it. In theory you can still try to emulate the hardware and reverse engineer the game code to attempt to emulate desired output ... but eventually that tactic won't be necessary.

"PS4EMX is FAKE!!!!"

It looks that way, but the truth is that without the right tools and time it's not possible for the very, very, very few people who are working on this project (like 2 or 3) to add much over time. I don't have a PS4 or PS4 games; I don't have much time to devote to reverse engineering it; I can't afford a high-end computer with a Blu-ray drive right now; and it's pretty much the same issue for other developers. If anyone wants to help PS4EMX, the first step would be to have the right access (PS4, PS4 games, Blu-ray, good computer with Blu-ray drive, hacking experience) to work on decrypting the game discs' S.E.L.F. file and such, and disassembling it by sections. If anyone wants to contribute these are the bare necessities, and having this would speed up and improve the project. Donations are being accepted here: http://www.ps4hacking.wordpress.com
