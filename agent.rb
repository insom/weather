require 'serialport'
require 'socket'

ss = TCPSocket.new('127.0.0.1', 2003)
s = SerialPort.open('/dev/ttyUSB0', baud: 9600)

while line = s.readline.strip
  next if line.empty?
  next if line == 'OHAI'
  matches = /^P([0-9.]*)T([0-9.]*)$/.match(line)
  ss.write("garage.pressure #{ matches[1] } #{ Time.now.utc.to_i }\n")
  ss.write("garage.temperature #{ matches[2] } #{ Time.now.utc.to_i }\n")
end
