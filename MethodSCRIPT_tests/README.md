# Emstat Pico Measurement using Methodscript 
For execution of any electrochemical measurement techniques like CV,DPV,SWV,OCP and Amperometry etc. we need one .mscr file (i.e Methodscript file) and other is .py file (i.e Python code file). The python code file should be compatible wih .mscr file.It means if we want to execute CV technique using methodscript file then python code should be related or compatible with this CV .mscr file, otherwise technique will not be executed.The python code helps in to convert raw data into graph plot.

## Python Data Files for different Techniques 
|Files Name|Purpose|
|---|---|
|[CV_es_PICO.py](https://github.com/TechnocultureResearch/Genotyper-Firmware/blob/dev/MethodSCRIPT_tests/CV_es_PICO.py)|This has python code for CV measurement|
|[ChronoAmp_es_PICO.py](https://github.com/TechnocultureResearch/Genotyper-Firmware/blob/dev/MethodSCRIPT_tests/ChronoAmp_es_PICO.py)|This has python code for Chronoamperometry  measurement|
|[DPV_es_PICO.py](https://github.com/TechnocultureResearch/Genotyper-Firmware/blob/dev/MethodSCRIPT_tests/DPV_es_PICO.py)|This has python code for DPV measurement|
|[EIS_es_PICO.py](https://github.com/TechnocultureResearch/Genotyper-Firmware/blob/dev/MethodSCRIPT_tests/EIS_es_PICO.py)|This has python code for EIS  measurement|
|[OCP_es_PICO.py](https://github.com/TechnocultureResearch/Genotyper-Firmware/blob/dev/MethodSCRIPT_tests/OCP_es_PICO.py)|This has python code for OCP measurement|
|[SWV_es_PICO.py](https://github.com/TechnocultureResearch/Genotyper-Firmware/blob/dev/MethodSCRIPT_tests/SWV_es_PICO.py)|This has python code for OCP measurement|

## Methodscript Data Files for different Techniques 
|Files Name|Purpose|
|---|---|
|[CV_es_pico.mscr](https://github.com/TechnocultureResearch/Genotyper-Firmware/blob/dev/MethodSCRIPT_tests/scripts/CV_es_pico.mscr)|This has Methodcript for CV measurement|
|[CAmp_es_pico.mscr](https://github.com/TechnocultureResearch/Genotyper-Firmware/blob/dev/MethodSCRIPT_tests/scripts/CAmp_es_pico.mscr)|This has Methodcript for Chronoamperometry  measurement|
|[DPV_es_pico.mscr](https://github.com/TechnocultureResearch/Genotyper-Firmware/blob/dev/MethodSCRIPT_tests/scripts/DPV_es_pico.mscr)|This has Methodcript for DPV measurement|
|[EIS_es_pico.mscr](https://github.com/TechnocultureResearch/Genotyper-Firmware/blob/dev/MethodSCRIPT_tests/scripts/EIS_es_pico.mscr)|This has Methodcript for EIS  measurement|
|[OCP_es_pico.mscr](https://github.com/TechnocultureResearch/Genotyper-Firmware/blob/dev/MethodSCRIPT_tests/scripts/OCP_methodscript.mscr)|This has Methodcript for OCP measurement|
|[SWV_es_pico.mscr](https://github.com/TechnocultureResearch/Genotyper-Firmware/blob/dev/MethodSCRIPT_tests/scripts/SWV_es_pico.mscr)|This has Methodcript for OCP measurement|

# How to troubleshhot Methodscript file of PStrace to Executable Methodscript for python

Step 1 : Open the CV (or any technique) Methodscript files in PStrace software as shown below 

![MS](https://user-images.githubusercontent.com/86110190/181878414-b4884632-3875-469e-ac3b-75df92a69d09.JPG)

Then Compare this CV methodscript file of PStrace with [example_cv.mscr](https://github.com/TechnocultureResearch/Genotyper-Firmware/blob/dev/MethodSCRIPT_tests/scripts/example_cv.mscr) (CV methodscript example file) provided by palmsens company (as shown below)

![exampleCV](https://user-images.githubusercontent.com/86110190/181880244-8bf8d143-e87d-4418-a031-693253b3f3f0.JPG)


Then we can see that there is some changes in example code like 
1. 4 to 6 line code `[set_pgstat_chan 1, set_pgstat_mode 0, set_pgstat_chan 0]` in PStrace methodscript file (as shown in image 1) can be removed or add. In the example code it has been removed to select default channel 0
2. 9th line code that is `[set_range_minmax da -500m 500m]` in PStrace methodscript file (as shown in image 1) is removed in example code  
3. 15 to 18 line code `[ pck_start, pck_add p, pck_add c, pck_end]` in PStrace methodscript file (as shown in image 1) is removed in example code

# How to Implement Different Technique in Emstate Pico Development Kit using Methodscipt with Python

## Methodscript For CV

```
e
var c
var p
set_pgstat_mode 2
set_max_bandwidth 40
set_range ba 100u
set_autoranging ba 1n 100u
#  set_e {E_begin} ---[comment line]
set_e -500m
cell_on
# autorange for 1s prior to CV   ---[comment line]
# meas_loop_ca p c {E_begin} {E_vertex2} {t_equilibration}   ---[comment line]

meas_loop_ca p c -500m 500m 10
endloop
# meas_loop_cv p c {E_begin} , {E_vtx1}, {E_vtx2},{E_step},{ scan_rate}   ---[comment line]
meas_loop_cv p c -500m -500m +500m 10m 100m 
	pck_start
	pck_add p
	pck_add c
	pck_end
endloop
on_finished:
cell_off
```
## Code Line used for enter CV parameter value in above Methodscript:
|Code line|Purpose|
|---|---|
|`set_e {E_begin}`|This code line is used to enter the `Ebegin` value of CV technique|
|`meas_loop_ca p c {E_begin} {E_vertex2} {t_equilibration}`|This code line is used to enter the `Ebegin` , `Evertex2` and ` tequilibration` value of CV technique|
|`meas_loop_cv p c {E_begin} , {E_vtx1}, {E_vtx2},{E_step},{ scan_rate}`|This code line is used to enter the `Ebegin` , `Evertex1`, `Evertex2`, `Estep` and  ` scanrate` value of CV technique|

## Methodscript For DPV

```
e
var c
var p
#var i
#store_var i 0i ja
# any changes in below 4 lines should
# will result in column index error
set_pgstat_chan 1
set_pgstat_mode 0
set_pgstat_chan 0
set_pgstat_mode 2
set_max_bandwidth 40
# set_range_minmax da {-Ebegin} {Amplitude+Eend}
set_range_minmax da -500m 700m
set_range ba 100u
set_autoranging ba 100n 100u
cell_on
#Equilibrate at -300mV and autorange for 2s prior to SWV
#Below line meas_loop_ca p c {Ebegin} {Eend} {tequilibration}
meas_loop_ca p c -500m 500m 5
endloop
# meas_loop_dpv p c {E_begin} {E_end} {E_step} {E_pulse} {t_pulse} {scan_rate}
meas_loop_dpv p c -500m 500m 10m 200m 20m 100m
	pck_start
	pck_add p
	pck_add c
	pck_end
endloop
on_finished:
cell_off
```
## Code Line used for enter DPV parameter value in above Methodscript:
|Code line|Purpose|
|---|---|
|`set_range_minmax da {-Ebegin} {Amplitude+Eend}`|In this code line, we have to enter the value of `Ebegin`, 'Amplitude` and `Eend`parameter value of DPV |
|`meas_loop_ca p c {Ebegin} {Eend} {tequilibration}`|This code line is used to enter the `Ebegin` , `Eend` and ` tequilibration` value of DPV technique|
|`meas_loop_dpv p c {E_begin} {E_end} {E_step} {E_pulse} {t_pulse} {scan_rate}`|This code line is used to enter the `Ebegin` , `Eend`, `Estep`, `Epulse`,`tpulse` and `scanrate` value of DPV technique|




