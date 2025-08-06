.PHONY all clean test getinfo_IPV4 multi_platform

all: getinfo_IPV4 multi_platform

getinfo_IPV4:
	$(MAKE) -C getinfo_IPV4

multi_platform:
	$(MAKE) -C multi_platform

clean:
	$(MAKE) -C getinfo_IPV4
	$(MAKE) -C multi_platform

test:
#	./scripts/test.sh

