#include <zephyr/kernel.h>

#include <device.h>
#include <devicetree.h>
#include <drivers/sensor.h>

#define SENS21231 DT_INST(0, sens21231)

#if DT_NODE_HAS_STATUS(SENS21231, okay)
#define SENS21231_LABEL DT_LABEL(SENS21231)
#else
#error Your devicetree has no enabled nodes with compatible information for SENS21231.
#define SENS21231_LABEL "<none>"
#endif

void main(void)
{
	const struct device *dev = device_get_binding(SENS21231_LABEL);

	if (dev == NULL) {
		printk("No device \"%s\" found; did initialization fail?\n",
		       SENS21231);
		return;
	} else {
		printk("Found device \"%s\"\n", SENS21231);
	}

	printk("Hello World 3! %s\n", CONFIG_BOARD);
}