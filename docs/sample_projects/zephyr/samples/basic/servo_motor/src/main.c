#include <zephyr.h>
#include <sys/printk.h>
#include <device.h>
#include <drivers/pwm.h>

#define PWM_NODE DT_ALIAS(pwm_servo)

#if !DT_NODE_HAS_STATUS(PWM_NODE, okay)
#error "Unsupported board: pwm-servo devicetree alias is not defined or enabled"
#endif

#define PERIOD_USEC	(20U * USEC_PER_MSEC)
#define STEP_USEC	100
#define MIN_PULSE_USEC	700
#define MAX_PULSE_USEC	2300

enum direction {
	DOWN,
	UP,
};

void main(void)
{
	const struct device *pwm;
	uint32_t pulse_width = MIN_PULSE_USEC;
	enum direction dir = UP;
	int ret;

	printk("Servomotor control\n");

	pwm = DEVICE_DT_GET(PWM_NODE);
	if (!device_is_ready(pwm)) {
		printk("Error: PWM device %s is not ready\n", pwm->name);
		return;
	}

	while (1) {
		ret = pwm_pin_set_usec(pwm, DT_PROP(DT_NODELABEL(pwm0), ch0_pin), PERIOD_USEC, pulse_width, 0);
		if (ret < 0) {
			printk("Error %d: failed to set pulse width\n", ret);
			return;
		}

		if (dir == DOWN) {
			if (pulse_width <= MIN_PULSE_USEC) {
				dir = UP;
				pulse_width = MIN_PULSE_USEC;
			} else {
				pulse_width -= STEP_USEC;
			}
		} else {
			pulse_width += STEP_USEC;

			if (pulse_width >= MAX_PULSE_USEC) {
				dir = DOWN;
				pulse_width = MAX_PULSE_USEC;
			}
		}

		k_sleep(K_SECONDS(0.2));
	}
}
