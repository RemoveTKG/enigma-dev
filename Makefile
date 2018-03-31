PATH := $(eTCpath)$(PATH)

.PHONY: ENIGMA all clean Game clean-game liblodepng libProtocols libGM required-directories .FORCE

ENIGMA: .FORCE libProtocols liblodepng
	$(MAKE) -C CompilerSource

clean: .FORCE
	$(MAKE) -C CompilerSource/ clean
	$(MAKE) -C CommandLine/emake/ clean
	$(MAKE) -C CommandLine/libGM/ clean
	$(MAKE) -C CommandLine/protos/ clean
	$(MAKE) -C CommandLine/testing/ clean
	$(MAKE) -C lodepng/ clean

all: liblodepng libProtocols libGM ENIGMA emake test-runner .FORCE

Game: liblodepng .FORCE
	$(MAKE) -C ENIGMAsystem/SHELL

clean-game: .FORCE
	$(MAKE) -C ENIGMAsystem/SHELL clean

liblodepng: .FORCE
	$(MAKE) -C lodepng/

libProtocols: .FORCE
	$(MAKE) -C CommandLine/protos/

libGM: .FORCE libProtocols
	$(MAKE) -C CommandLine/libGM/

emake: libGM .FORCE
	$(MAKE) -C CommandLine/emake/

test-runner: emake .FORCE
	$(MAKE) -C CommandLine/testing/

required-directories: .FORCE
	mkdir -p "$(WORKDIR)"
	mkdir -p "$(CODEGEN)Preprocessor_Environment_Editable/"

.FORCE:
