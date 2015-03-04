This is a slightly modified version of apm_planner that will be compiled on an ARM board using a modified version of qt4 (as double). The qt4 branch compiles fine with the modified qt4 but since we wanted to add freenect support we needed to change a few minor things. 

We compiled in qtcreator 2.0.1 and qt4.8.7 using qmake-qt4 on Ubunutu 12.04

I don't know what happens when you use these modified files with OSX or Windows so I will remove those instructions. I have also remove the qt4 and openscene dependecies because we will assume that you are using qt4 compiled as a double and openscene isn't officially supports in 12.04. 


APM Planner

Project:
http://github.com/diydrones/apm_planner

Files:
https://github.com/diydrones/apm_planner

Credits:
http://planner2.ardupilot.com/credits-and-contributors/


Documentation
=============
see http://planner2.ardupilot.com


Linux 
=====

Building on Linux (tested against Ubuntu 13.10):

1) Install the required packages:

```
sudo apt-get install phonon libqt4-opengl-dev \
 libphonon-dev libphonon4 phonon-backend-gstreamer \
 qtcreator libsdl1.2-dev libflite1 flite1-dev build-essential \
 libssl-dev libqt4-opengl-dev libudev-dev \
 libsndfile1-dev libqt4-sql-sqlite
```

2) Clone the repository in your workspace:

```
cd ~/workspace
git clone https://github.com/diydrones/apm_planner
```

3) Build APM Planner:

```
cd ~/workspace/apm_planner
qmake-qt4 qgroundcontrol.pro
make
```

Or try `qmake qgroundcontrol.pro` if the `qmake-qt4` command doesn't exist on your version of Ubuntu. This will only work if the Qt version install on your machine is Qt4.8.x, this can be checked using `qmake -v'

4) Run APM Planner:

```
./release/apmplanner2
```

5) Permanent installation (optional, if you'd like to install APM Planner in a fixed location)
 
There are two ways to do this:
a) You can build a .deb using ```scripts/LinuxBuildPackage.sh```, and then install the deb via ```dpkg -i ~/Documents/APMPlanner2-$NOW.deb``` (where $NOW is today's date). This should add it to your launcher too.

b) Alternatively, run ```sudo make install```. This will place the binary in your /bin/ folder and corresponding files in /share/.




Repository Layout (2014-3-28: out-of-date, needs to be fixed)
=================
```
qgroundcontrol:
	demo-log.txt
	license.txt 
	qgcunittest.pro - For the unit tests.
	qgcunittest.pro.user
	qgcvideo.pro
	qgroundcontrol.pri - Used by qgroundcontrol.pro
	qgroundcontrol.pro - Project opened in QT to run qgc.
	qgroundcontrol.pro.user 
	qgroundcontrol.qrc - Holds many images.
	qgroundcontrol.rc - line of code to point toward the images
	qserialport.pri - generated by qmake.
	testlog.txt
	testlog2.txt 
	user_config.pri.dist - Custom message specs to be added here. 
data: 
	Maps from yahoo and kinect and earth. 
deploy: 
	Install and uninstall for win32.
	Create a debian packet.
	Create .DMG file for publishing for mac.
	Audio test on mac.	
doc: 
	Doxyfile is in this directory and information for creating html documentation for qgc.
files: 
	Has the audio for the vehicle and data output. 
		ardupilotmega: 
			widgets and tool tips for pilot heading for the fixed wing.
			tooltips for quadrotor
		flightgear:
			Aircraft: 
				Different types of planes and one jeep. 
			Protocol: 
				The protocol for the fixed_wings and quadrotor and quadhil.holds info about the fixed wing yaw, roll etc. 					Quadrotor. Agian holds info about yaw, roll etc.
		Pixhawk:
			Widgets for hexarotor. Widgets and tooltips for quadrotor.
		vehicles: 
			different vehicles. Seems to hold the different kinds of aircrafts as well as files for audio and the hexarotor 			and quadrotor.
		widgets: 
			Has a lot of widgets defined for buttons and sliders.

images: 
	For the UI. Has a bunch of different images such as images for applications or actions or buttons.
lib: 
	SDL is located in this direcotry. 
	Msinttypes: 
		Defines intteger types for microsoft visual studio. 
	sdl:
		Information about the library and to run the library on different platforms. 
mavlink: 
	The files for the library mavlink. 
qgcunittest: 
	Has the unittests for qgc
settings: 
	Parameter lists for alpha, bravo and charlie. 
	Data for stereo, waypoints and radio calibrartion. 
src:
	Code for QGCCore, audio output, configuration, waypoints, main and log compressor.
	apps - Code for mavlink generation and for a video application.
	comm - Code for linking to simulation, mavlink, udp, xbee, opal, flight gear and interface.
	Has other libraries. Qwt is in directory named lib. The other libraries are in libs.
	lib - qwt library
	libs - eigen, opmapcontrol, qestserialport, qtconcurrent, utils.
	input - joystick and freenect code.
	plugins - Qt project for PIXHAWK plugins.
	uas - Ardu pilot, UAS, mavlink factory, uas manager, interface, waypoint manager and slugs.
	ui - Has code for data plots, waypoint lists and window congfiguration. All of the ui code.
thirdParty: 
	Library called lxbee.
	Library called QSerialPort.
```
