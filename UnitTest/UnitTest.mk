##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=UnitTest
ConfigurationName      :=Release
WorkspacePath          :=D:/Alex/CourseWork
ProjectPath            :=D:/Alex/CourseWork/UnitTest
IntermediateDirectory  :=Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alex
Date                   :=01/10/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/mingw-w64/i686-5.3.0-posix-dwarf-rt_v4/bin/i686-w64-mingw32-g++.exe
SharedObjectLinkerName :=C:/mingw-w64/i686-5.3.0-posix-dwarf-rt_v4/bin/i686-w64-mingw32-g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="UnitTest.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -O2
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)UnitTest++ 
ArLibs                 :=  "libUnitTest++.a" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/mingw-w64/i686-5.3.0-posix-dwarf-rt_v4/bin/i686-w64-mingw32-ar.exe rcu
CXX      := C:/mingw-w64/i686-5.3.0-posix-dwarf-rt_v4/bin/i686-w64-mingw32-g++.exe
CC       := C:/mingw-w64/i686-5.3.0-posix-dwarf-rt_v4/bin/i686-w64-mingw32-gcc.exe
CXXFLAGS :=   $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw-w64/i686-5.3.0-posix-dwarf-rt_v4/bin/i686-w64-mingw32-as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/up_http_client_HTTPClient.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "Release"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Alex/CourseWork/UnitTest/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/up_http_client_HTTPClient.cpp$(ObjectSuffix): ../http_client/HTTPClient.cpp $(IntermediateDirectory)/up_http_client_HTTPClient.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Alex/CourseWork/http_client/HTTPClient.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_http_client_HTTPClient.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_http_client_HTTPClient.cpp$(DependSuffix): ../http_client/HTTPClient.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_http_client_HTTPClient.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_http_client_HTTPClient.cpp$(DependSuffix) -MM ../http_client/HTTPClient.cpp

$(IntermediateDirectory)/up_http_client_HTTPClient.cpp$(PreprocessSuffix): ../http_client/HTTPClient.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_http_client_HTTPClient.cpp$(PreprocessSuffix) ../http_client/HTTPClient.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r Release/


