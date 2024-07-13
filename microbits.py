TIMER = 0
DISTANCE = 0
RIGHT_WAY_FLAG = False
basic.show_icon(IconNames.No)

# Pedestrian push to cross buttons
def on_button_pressed_b():
  pins.digital_write_pin(DigitalPin.P0, 1)
input.on_button_pressed(Button.B, on_button_pressed_b)

def on_button_pressed_a():
  pins.digital_write_pin(DigitalPin.P0, 1)
input.on_button_pressed(Button.A, on_button_pressed_a)


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
    pins.digital_write_pin(DigitalPin.P0, 1)
    basic.pause(50) # Send signal to controller that light ready to change
    pins.digital_write_pin(DigitalPin.P0, 0)
pins.on_pulsed(DigitalPin.P2, PulseValue.LOW, on_pulsed_p2_low)
