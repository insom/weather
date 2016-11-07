# Weather

An nRF2401+ / BMP180 remote weather sensor thing. [Blog post is here][bp]

[bp]: http://insom.github.io/project/weather/

#### Sensor Node

<table>
<tr><th>Arduino Pin</th><th>BMP180 Pin</th><th>nRF2401+ Pin</th></tr>
<tr><td>GND</td><td>GND</td><td>GND</td></tr>
<tr><td>VCC</td><td>VCC</td><td>-</td></tr>
<tr><td>3.3</td><td>-</td><td>VCC</td></tr>
<tr><td>7</td><td>-</td><td>CE</td></tr>
<tr><td>8</td><td>-</td><td>CSN</td></tr>
<tr><td>11</td><td>-</td><td>MOSI</td></tr>
<tr><td>12</td><td>-</td><td>MISO</td></tr>
<tr><td>13</td><td>-</td><td>SCK</td></tr>
<tr><td>A4</td><td>SDA</td><td>-</td></tr>
<tr><td>A5</td><td>SCL</td><td>-</td></tr>
</table>

#### Receiver Node

<table>
<tr><th>Arduino Pin</th><th>nRF2401+ Pin</th></tr>
<tr><td>GND</td><td>GND</td></tr>
<tr><td>3.3</td><td>VCC</td></tr>
<tr><td>7</td><td>CE</td></tr>
<tr><td>8</td><td>CSN</td></tr>
<tr><td>11</td><td>MOSI</td></tr>
<tr><td>12</td><td>MISO</td></tr>
<tr><td>13</td><td>SCK</td></tr>
</table>

