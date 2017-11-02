syntax on           "각 파일의 성격(?)에 맞게 색깔로 보여 준다.
set cindent         "C언어를 작성할때 자동 indentition
set autoindent      "자동으로 들여쓰기
"set tabstop=4       " Tab size
set nu              " linenumber
"set nobackup       " 백업 파일을 만들지 않음
"colorscheme molokai   " color scheme
"set ignorecase     " 검색,편집 치환시에 대소문자 구분하지 않음
set smartindent     " 코딩 할때 if, for 같은 것을 입력 하고 다음 라인으로 이동시 들려쓰기
"set shiftwidth=4    " smartindent 사용시, 자동 들여쓰기 size
"set expandtab      " [tab] 키를 입력 하였을때 tab에 대당하는 space 만큼 이동(파이썬 코딩시)
set encoding=utf-8  " 컴퓨터 또는 개발 언어에서 기본 인코딩 타입
"set list            " tab, 개행을 보여줌
set fileencodings=euc-kr
"set fileformats=unix       " unix 형식 저장 - ^V
"set fileformats=dox        " dox 형식 저장 - ^V^M

set incsearch       " 키워드를 입력할때 검색하는 점진 검색 사용
set hlsearch        " 검색어 강조 기능

set nocompatible	"To highlight scala language
filetype indent on	"To highlight scala language
set ic			"To highlight scala language
set hls			"To highlight scala language
set lbr			"To highlight scala language
"set list		


set tags=./tags,../tags,../../tags
"set spell          " 영문 spelling check
"set showmatch          " 짝이 맞는 괄호를 보여줌

"set wildmenu            " wildmenu 
"set wildmode=list:longest,full

"set clipboard=unnamed  " use default register only

filetype plugin on      "use file type plugin  refers... ~/.vim/ftplugin/




"============================ ctags ==========================="

if version >= 500
	func! Sts()
		let st = expand("<cword>")
		exe "sts ".st
	endfunc
	nmap ,st :call Sts()<cr>

	func! Tj()
		let st = expand("<cword>")
		exe "tj ".st
	endfunc
	nmap ,tj :call Tj()<cr>
endif

map <C-\> :vsp <CR>:exec("tag ".expand("<cword>"))<CR>
"======================== cscope ============================"


set csprg=/usr/bin/cscope
set csto=0
set cst
set nocsverb

if filereadable("./cscope.out")
	cs add cscope.out
endif
set csverb

func! Css()
	let css = expand("<cword>")
	new 
	exe "cs find s ".css
	if getline(1) == " "
		exe "q!"
	endif
endfunc
nmap ,css : call Css()<cr>


func! Csc()
	let csc = expand("<cword>")
	new 
	exe "cs find c ".csc
	if getline(1) == " "
		exe "q!"
	endif
endfunc
nmap ,csc : call Csc()<cr>


func! Csd()
	let csd = expand("<cword>")
	new 
	exe "cs find d ".csd
	if getline(1) == " "
		exe "q!"
	endif
endfunc
nmap ,csd : call Csd()<cr>


func! Csg()
	let csg = expand("<cword>")
	new 
	exe "cs find g ".csg
	if getline(1) == " "
		exe "q!"
	endif
endfunc
nmap ,csg : call Csg()<cr>


"jgraph macro
map <F2> :!./makejgr %:r<CR>

