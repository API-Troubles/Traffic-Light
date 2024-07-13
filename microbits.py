# Here is my micro:bit code so fat
# Updated manually

TIMER = 0
DISTANCE = 0
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
  global TIMER
  basic.show_icon(IconNames.Yes)
  basic.pause(5000)
  TIMER = 10
  for index in range(9):
    basic.show_number(TIMER)
    TIMER += -1
    basic.pause(900)
    basic.show_string("")
    basic.pause(100)
    
pins.on_pulsed(DigitalPin.P2, PulseValue.HIGH, on_pulsed_p2_high)
