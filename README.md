# LinuxInstalledAppsFilter

[English]
I created this script (?) because I changed from Ubuntu to POP_OS. One of the biggest struggles for me when we're talking about formatting a PC is to list everything I had installed because I'm lazy. Luckily, Linux provides ways of listing everything we have installed and paste it into a file.

Then, that's one problem solved: We have the list of things intalled in our old OS. So we install the new one and create the list of things installed on this one.

What this script does is a "substraction" of those files, so you can see what you don't have already and, if you want it, you install that new software.

When you list everything, the terminal prints it in a very cute way, but for our purpose the only thing we need is the name of the package. This program creates two new files from the ones you provide. This new ones only contain the packages names so it compares easily.

I think this is everything you need to know, hope it works for you. I provide the files I created so you can try it on your own.

[Español]
Creé este script (?) porque cambié de Ubuntu a POP_OS. Una de las dificultades para mí cuando se trata de formatear/instalar un nuevo SO en una computadora es listar todo lo que tenía instalado porque soy peresozo. Afortunadamente, Linux nos proporciona maneras de listar todo lo que teníamos instalado y pegarlo en un archivo.

Así, un problema queda resuelto: Tenemos la lista de cosas instaladas en nuestro antiguo SO. Entonces instalamos el nuevo y creamos una lista también de este.

Lo que hace este script es una "resta" de esos archivos, para que puedas ver lo que no tienes instalado en el nuevo y, si lo deseas, instalarlo en el nuevo SO.

Cuando listas todo, la terminal lo imprime en un formato muy lindo, pero para nuestros propósitos solamente necesitamos el nombre de los paquetes. Este programa crea dos archivos nuevos a partir de los que le proporcionas. Estos nuevos archivos solamente contienen el nombre de los paquetes para que se pueda comparar más fácilmente.

Creo que esto es todo lo que necesitas saber, espero que te funcione. También proporciono los archivos que creé para que lo intentes por tu cuenta.

***Creating the lists***
apt list --installed > APTFileName.txt
snap list > SnapFileName.txt
flatpak list > FlatpakFileName.txt
dpkg -l > DPGKFileName.txt
