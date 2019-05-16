// Generated by Haxe 3.4.7
#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_src_Main
#include <src/Main.h>
#endif
#ifndef INCLUDED_sys_io_Process
#include <sys/io/Process.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_3cb1ff7e3af8b400_10_main,"src.Main","main",0xed2a5664,"src.Main.main","Main.hx",10,0x087e5c05)
HX_LOCAL_STACK_FRAME(_hx_pos_3cb1ff7e3af8b400_41_getBranches,"src.Main","getBranches",0xd2c8537b,"src.Main.getBranches","Main.hx",41,0x087e5c05)
static const ::String _hx_array_data_7b2af223_3[] = {
	HX_("branch",a2,fe,18,13),
};
HX_LOCAL_STACK_FRAME(_hx_pos_3cb1ff7e3af8b400_46_deleteBranch,"src.Main","deleteBranch",0xcb5fe658,"src.Main.deleteBranch","Main.hx",46,0x087e5c05)
HX_LOCAL_STACK_FRAME(_hx_pos_3cb1ff7e3af8b400_7_boot,"src.Main","boot",0xe5efa25d,"src.Main.boot","Main.hx",7,0x087e5c05)
namespace src{

void Main_obj::__construct() { }

Dynamic Main_obj::__CreateEmpty() { return new Main_obj; }

void *Main_obj::_hx_vtable = 0;

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{
	hx::ObjectPtr< Main_obj > _hx_result = new Main_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Main_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x18d5e0fd;
}

 ::haxe::io::Input Main_obj::input;

void Main_obj::main(){
            	HX_GC_STACKFRAME(&_hx_pos_3cb1ff7e3af8b400_10_main)
HXLINE(  11)		::Array< ::String > branches = ::src::Main_obj::getBranches();
HXLINE(  13)		 ::EReg currentBranchRegexp =  ::EReg_obj::__alloc( HX_CTX ,HX_("\\*",4e,50,00,00),HX_("",00,00,00,00));
HXLINE(  15)		{
HXLINE(  15)			int _g = (int)0;
HXDLIN(  15)			while((_g < branches->length)){
HXLINE(  15)				::String branch = branches->__get(_g);
HXDLIN(  15)				_g = (_g + (int)1);
HXLINE(  16)				::String branch1 = ::StringTools_obj::trim(branch);
HXLINE(  19)				bool _hx_tmp;
HXDLIN(  19)				bool _hx_tmp1;
HXDLIN(  19)				if ((branch1 != HX_("master",a2,80,20,bb))) {
HXLINE(  19)					_hx_tmp1 = (branch1 == HX_("",00,00,00,00));
            				}
            				else {
HXLINE(  19)					_hx_tmp1 = true;
            				}
HXDLIN(  19)				if (!(_hx_tmp1)) {
HXLINE(  19)					_hx_tmp = currentBranchRegexp->match(branch1);
            				}
            				else {
HXLINE(  19)					_hx_tmp = true;
            				}
HXLINE(  18)				if (_hx_tmp) {
HXLINE(  23)					continue;
            				}
HXLINE(  26)				::String lastBranchCommit =  ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::__new(4)->init(0,HX_("log",84,54,52,00))->init(1,HX_("--pretty=format:\"%ad\"",e0,2f,70,17))->init(2,HX_("-1",64,27,00,00))->init(3,branch1))->_hx_stdout->readAll(null())->toString();
HXLINE(  28)				::Sys_obj::print(((HX_("\n[BRANCH]: ",b0,b7,0e,9a) + branch1) + HX_("\n",0a,00,00,00)));
HXLINE(  29)				::Sys_obj::print(((HX_("[LAST_UPDATE]: ",0c,5d,d1,ea) + lastBranchCommit) + HX_("\n",0a,00,00,00)));
HXLINE(  30)				::Sys_obj::print(HX_("Delete this branch? [Y/N]: ",76,64,9c,8f));
HXLINE(  31)				::String userInput = ::src::Main_obj::input->readLine();
HXLINE(  33)				bool _hx_tmp2;
HXDLIN(  33)				if ((userInput != HX_("y",79,00,00,00))) {
HXLINE(  33)					_hx_tmp2 = (userInput == HX_("Y",59,00,00,00));
            				}
            				else {
HXLINE(  33)					_hx_tmp2 = true;
            				}
HXDLIN(  33)				if (_hx_tmp2) {
HXLINE(  34)					::src::Main_obj::deleteBranch(branch1);
            				}
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))

::Array< ::String > Main_obj::getBranches(){
            	HX_GC_STACKFRAME(&_hx_pos_3cb1ff7e3af8b400_41_getBranches)
HXDLIN(  41)		return  ::sys::io::Process_obj::__alloc( HX_CTX ,HX_("git",12,84,4e,00),::Array_obj< ::String >::fromData( _hx_array_data_7b2af223_3,1))->_hx_stdout->readAll(null())->toString().split(HX_("\n",0a,00,00,00));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,getBranches,return )

void Main_obj::deleteBranch(::String branch){
            	HX_STACKFRAME(&_hx_pos_3cb1ff7e3af8b400_46_deleteBranch)
HXDLIN(  46)		if ((::Sys_obj::command(HX_("git",12,84,4e,00),::Array_obj< ::String >::__new(3)->init(0,HX_("branch",a2,fe,18,13))->init(1,HX_("-d",97,27,00,00))->init(2,branch)) != (int)0)) {
HXLINE(  47)			::Sys_obj::print(((HX_("Would you like to force delete branch (",22,4d,c6,49) + branch) + HX_(")? [Y/n]: ",bc,21,5a,92)));
HXLINE(  49)			::String userInput = ::src::Main_obj::input->readLine();
HXLINE(  50)			bool _hx_tmp;
HXDLIN(  50)			if ((userInput != HX_("y",79,00,00,00))) {
HXLINE(  50)				_hx_tmp = (userInput == HX_("Y",59,00,00,00));
            			}
            			else {
HXLINE(  50)				_hx_tmp = true;
            			}
HXDLIN(  50)			if (_hx_tmp) {
HXLINE(  51)				::Sys_obj::command(HX_("git",12,84,4e,00),::Array_obj< ::String >::__new(3)->init(0,HX_("branch",a2,fe,18,13))->init(1,HX_("-D",77,27,00,00))->init(2,branch));
            			}
            		}
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Main_obj,deleteBranch,(void))


Main_obj::Main_obj()
{
}

bool Main_obj::__GetStatic(const ::String &inName, Dynamic &outValue, hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { outValue = main_dyn(); return true; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { outValue = ( input ); return true; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"getBranches") ) { outValue = getBranches_dyn(); return true; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"deleteBranch") ) { outValue = deleteBranch_dyn(); return true; }
	}
	return false;
}

bool Main_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"input") ) { input=ioValue.Cast<  ::haxe::io::Input >(); return true; }
	}
	return false;
}

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *Main_obj_sMemberStorageInfo = 0;
static hx::StaticInfo Main_obj_sStaticStorageInfo[] = {
	{hx::fsObject /*::haxe::io::Input*/ ,(void *) &Main_obj::input,HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static void Main_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Main_obj::input,"input");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Main_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Main_obj::input,"input");
};

#endif

hx::Class Main_obj::__mClass;

static ::String Main_obj_sStaticFields[] = {
	HX_HCSTRING("input","\x0a","\xc4","\x1d","\xbe"),
	HX_HCSTRING("main","\x39","\x38","\x56","\x48"),
	HX_HCSTRING("getBranches","\x46","\x86","\x43","\xf0"),
	HX_HCSTRING("deleteBranch","\x2d","\x25","\xb1","\x79"),
	::String(null())
};

void Main_obj::__register()
{
	hx::Object *dummy = new Main_obj;
	Main_obj::_hx_vtable = *(void **)dummy;
	hx::Static(__mClass) = new hx::Class_obj();
	__mClass->mName = HX_HCSTRING("src.Main","\x23","\xf2","\x2a","\x7b");
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Main_obj::__GetStatic;
	__mClass->mSetStaticField = &Main_obj::__SetStatic;
	__mClass->mMarkFunc = Main_obj_sMarkStatics;
	__mClass->mStatics = hx::Class_obj::dupFunctions(Main_obj_sStaticFields);
	__mClass->mMembers = hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = hx::TCanCast< Main_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Main_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Main_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Main_obj_sStaticStorageInfo;
#endif
	hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void Main_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_3cb1ff7e3af8b400_7_boot)
HXDLIN(   7)		input = ::Sys_obj::_hx_stdin();
            	}
}

} // end namespace src
