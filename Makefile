.PHONY: clean All

All:
	@echo "----------Building project:[ UnitTest - Release ]----------"
	@cd "UnitTest" && "$(MAKE)" -f  "UnitTest.mk"
clean:
	@echo "----------Cleaning project:[ UnitTest - Release ]----------"
	@cd "UnitTest" && "$(MAKE)" -f  "UnitTest.mk" clean
