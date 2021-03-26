# PSCon2Switch
## PSコントローラをスイッチにつなぐ
- <https://tangential-star.hatenablog.jp/entry/20201107/1604761008>に従って、IDE,STL,SwitchControlLibraryをインストール
- Arduino pro micro使用。ただし、ボードはLeonardoを選んでおく。
- <https://github.com/fujigaya2/PSCon2Switch/blob/main/schematic.png>のようにつなげば、動くたぶん。
- ボードがうまく書き込めていれば、windowsのデバイスマネージャで、<https://github.com/fujigaya2/PSCon2Switch/blob/main/device.jpg>のようなVID,PIDで見えるはず。
- こんなボードにして動いている。<https://seesaawiki.jp/fujigaya2/d/Mascon2kbd> 
### 使用ライブラリ
- Switch Control Library（V2.0.0)<https://github.com/celclow/SwitchControlLibrary>

- PSX Controller Decoder Library (DenshaMascon.cpp)  
Written by: Kevin Ahrendt June 22nd, 2008 Modified by: Yaasan / Desktop Station Dec 15, 2015
