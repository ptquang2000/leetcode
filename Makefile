PHONY := all
all:
	go test -v ./cmd/...

run:
	go test -v ./cmd/... -run $(test)

PHONY := FORCE
FORCE:

# Generate day directories
PHONY += generate
generate:
	@go generate

PHONY += clean
clean:
	rm -rf day*
