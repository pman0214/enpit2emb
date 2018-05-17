# Zumo with GR-Peach 開発環境

## 準備

gitはsubmoduleも含めてcloneしておく。

```
$ git clone git@github.com:pman0214/enpit2emb.git
$ cd enpit2emb
$ git submodule init
$ git submodule update
```

### Windowsユーザ

TrueSTDUIOを入れ、このレポジトリをインポートする。

### Macユーザ

homebrewで arm-none-eabi-gcc をインストールする。

```
$ brew tap caskroom/cask
$ brew cask install gcc-arm-embedded
```

コンフィギュレータをコンパイル or ダウンロードする。

コンパイルする場合はbrewでboostを入れてコンパイルする。

```
$ brew install boost
$ cd asp-1.9.2-utf8/cfg
$ make clean; make
```

コンパイルがうまくいかない人はダウンロードすると良い。
[https://www.toppers.jp/cfg-download.html](https://www.toppers.jp/cfg-download.html)

`asp-1.9.2-utf8/cfg/cfg` の中にダウンロードした `cfg` をコピー．
もしかしたら実行権限を設定する必要があるかも (``chmod +x cfg``)

## コンパイル方法

TrueSTDUIOの人はビルドすればOK。
ただし、git submoduleの ``example/README.md`` に書いてある通り、各種Makefileの ``USE_TRUESTUDIO`` を ``true`` に変更すること。

Macの人は　``app.cpp`` など開発したアプリソースのあるディレクトリで以下を実行。

```
$ make asp.bin
```

## 書き込み（ダウンロード）方法

Zumoの電源は切っておく（書き込み後に急に動作したりすると困るため）。

Zumoのmicro USBコネクタ（角に近い方）を使ってPCに接続すると「MBED」ディスクが現れるので、ビルドでできた ``asp.bin`` をコピーしてしばらく待つ。
「MBED」ディスクが一度切断されたら書き込み完了。

Macの場合はコマンドでやる方が早い。

```
cp asp.bin /Volumes/MBED
```

書き込んだらZumoの電源スイッチを入れ、赤いボードのリセットボタンを押す。
