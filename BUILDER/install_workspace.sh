#!/bin/bash

set -e
set -u

#-----------------------------------------------
#		Input
#-----------------------------------------------

#rien
#list project is define in DataProject.mk

#usage debug
#sudo ./install_workspace.sh > debug.txt
#cat ./debug.txt | grep find

#------------------------------------------------------------------------------------
#		main
#------------------------------------------------------------------------------------

if [[ "$(uname)" == "Linux" ]]
then
		if [[ $USER != "root" ]]
		then
			echo ""
			echo "Error : this script must be launch in sudo "
			echo ""
			exit 1
			
		fi
		
		#gcc & intel
		cbicc gcc installworkspace
		cbicc java installworkspace
else
		#visual & intel & mingw
		cbicc visual installworkspace
		cbicc java installworkspace
fi	

#------------------------------------------------------------------------------------
#		end
#------------------------------------------------------------------------------------
