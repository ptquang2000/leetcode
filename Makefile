PHONY := all
all:
	@go clean -testcache
	@go test -v ./cmd/...

run:
	@go clean -testcache
	@go test -v ./cmd/... -run $(test)

PHONY := FORCE
FORCE:

# Generate day directories
PHONY += generate
generate:
	@go generate

PHONY += clean
clean:
	rm -rf day*
