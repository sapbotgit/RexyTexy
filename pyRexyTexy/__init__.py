import serial, sys

class Screen:
  def __init__(self, port="COM1"):
    try:
      self.ser = serial.Serial(port, 9600)
    except:
      self.ser = sys.stdout
  def draw(x:int, y:int, state:bool):
    st = {True:1, False:0}
    self.ser.write(bytes(f"XY {x} {y} {st[state]};"))
  def text(txt="Hello World"):
    self.ser.write(bytes(f"TEXT {txt};"))
