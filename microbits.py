# Why are these seperate from the arduino?
# It's easier to anage the button state
# (I.e keep it on until light changed), and
# side bonus the display is easy to use!

TIMER = 0
DISTANCE = 0
RIGHT_WAY_FLAG = False
basic.show_icon(IconNames.No)

def pulse_signal(pin):
  pins.digital_write_pin(pin, 1)
  basic.pause(10)
  pins.digital_write_pin(pin, 0)

def ped_call():
  if not RIGHT_WAY_FLAG:
    pins.digital_write_pin(DigitalPin.P0, 1)
    pulse_signal(DigitalPin.P1)

input.on_button_pressed(Button.B, ped_call)
input.on_button_pressed(Button.A, ped_call)


# On receiving right of way signal
def on_pulsed_p2_high():
  pins.digital_write_pin(DigitalPin.P0, 0) # reset timer
  global TIMER
  global RIGHT_WAY_FLAG
  RIGHT_WAY_FLAG = True
  basic.show_icon(IconNames.Yes)
pins.on_pulsed(DigitalPin.P2, PulseValue.HIGH, on_pulsed_p2_high)
  
# Trigger warning countdown
def on_pulsed_p2_low():
  if RIGHT_WAY_FLAG: # Only if we got right of way
    global RIGHT_WAY_FLAG
    global TIMER
    RIGHT_WAY_FLAG = False
    TIMER = 9
    for _ in range(9):
      basic.show_number(TIMER)
      TIMER += -1
      basic.pause(600)       # Due to a weird timing bug this loop
      basic.show_string("")  # intentionally DOESN't add to 1 second
      basic.pause(100)
    basic.show_icon(IconNames.No)
    pulse_signal(DigitalPin.P0) # Tell controller we're done
pins.on_pulsed(DigitalPin.P2, PulseValue.LOW, on_pulsed_p2_low)
