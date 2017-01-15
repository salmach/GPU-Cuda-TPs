# Usefull for
#
#		builder_api
#
# et accessoirement
#
#		linux clean
#		linux_workspace_all
#		

#################################################
#						builderapi		 		#
#################################################


###############
#	CPP  	  #
###############

#list ordonner des projest a builder

LIST_PROJECTS:=
 
override LIST_PROJECTS+= CppTest
override LIST_PROJECTS+= BilatTools_CPP
override LIST_PROJECTS+= BilatTools_OMP
override LIST_PROJECTS+= BilatTools_OpenCV
override LIST_PROJECTS+= BilatTools_V4L_Linux
override LIST_PROJECTS+= BilatTools_Cuda

override LIST_PROJECTS+= BilatTools_Image
override LIST_PROJECTS+= BilatTools_Image_CV
override LIST_PROJECTS+= BilatTools_Cuda_Image
override LIST_PROJECTS+= BilatTools_Cuda_Image_CV

override LIST_PROJECTS+= BilatTools_Intel_MKL


###############
#	JAVA	  #
###############

LIST_PROJECTS_JAVA:=
override LIST_PROJECTS_JAVA+= 

#################################################
#						End	 			 		#
#################################################
