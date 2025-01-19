obj-y :=

-include Config.mk
-include ./src/Makefile

%.o: %.c
	# Compiling $@
	@$(CC) -c $< -o $@

%.gch: %.h
	# Compiling $@
	@$(CC) -c $< -o $@
