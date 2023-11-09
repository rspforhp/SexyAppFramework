#ifndef __SEXYAPPBASE_H_
#define __SEXYAPPBASE_H_


#include "Common.h"
#include "Rect.h"
#include "Color.h"
#include "ButtonListener.h"
#include "DialogListener.h"
#include "Buffer.h"
#include "CritSect.h"
#include "SharedImage.h"
#include "Ratio.h"
#include <Windows.h>



#ifdef WINAPI64
#define WINAPI64 long __stdcall
#endif

using namespace std;


//Use a long _stdcall to explicitly cast to x64 builds...This is not located anywhere else and is also not located
//in ANY of the windows headers.  This is the first library to use this..However our build architecture is x86.  Further testing is needed..

namespace ImageLib
{
	class Image;
};

namespace Sexy
{
	class WidgetManager;
	class DDInterface;
	class Image;
	class DDImage;
	class Widget;
	class SoundManager;
	class MusicInterface;
	class MemoryImage;
	class HTTPTransfer;
	class Dialog;

	class ResourceManager;

	class WidgetSafeDeleteInfo
	{
	public:
		int						mUpdateAppDepth;
		Widget* mWidget;
	};

	typedef list<WidgetSafeDeleteInfo> WidgetSafeDeleteList;
	typedef set<MemoryImage*> MemoryImageSet;
	typedef map<int, Dialog*> DialogMap;
	typedef list<Dialog*> DialogList;
	typedef list<MSG> WindowsMessageList;
	typedef vector<string> StringVector;

	typedef map<string, SexyString> StringSexyStringMap;
	typedef map<string, string> StringStringMap;
	typedef map<string, wstring> StringWStringMap;
	typedef map<string, bool> StringBoolMap;
	typedef map<string, int> StringIntMap;
	typedef map<string, double> StringDoubleMap;
	typedef map<string, StringVector> StringStringVectorMap;
	typedef int SWORD;//24 bit word integer type.




	enum
	{
		CURSOR_POINTER,
		CURSOR_HAND,
		CURSOR_DRAGGING,
		CURSOR_TEXT,
		CURSOR_CIRCLE_SLASH,
		CURSOR_SIZEALL,
		CURSOR_SIZENESW,
		CURSOR_SIZENS,
		CURSOR_SIZENWSE,
		CURSOR_SIZEWE,
		CURSOR_WAIT,
		CURSOR_NONE,
		CURSOR_CUSTOM,
		NUM_CURSORS
	};

	enum
	{
		DEMO_MOUSE_POSITION,
		DEMO_ACTIVATE_APP,
		DEMO_SIZE,
		DEMO_KEY_DOWN,
		DEMO_KEY_UP,
		DEMO_KEY_CHAR,
		DEMO_CLOSE,
		DEMO_MOUSE_ENTER,
		DEMO_MOUSE_EXIT,
		DEMO_LOADING_COMPLETE,
		DEMO_REGISTRY_GETSUBKEYS,
		DEMO_REGISTRY_READ,
		DEMO_REGISTRY_WRITE,
		DEMO_REGISTRY_ERASE,
		DEMO_FILE_EXISTS,
		DEMO_FILE_READ,
		DEMO_FILE_WRITE,
		DEMO_HTTP_RESULT,
		DEMO_SYNC,
		DEMO_ASSERT_STRING_EQUAL,
		DEMO_ASSERT_INT_EQUAL,
		DEMO_MOUSE_WHEEL,
		DEMO_HANDLE_COMPLETE,
		DEMO_VIDEO_DATA,
		DEMO_IDLE = 31
	};

	enum {
		FPS_ShowFPS,
		FPS_ShowCoords,
		Num_FPS_Types
	};

	enum
	{
		UPDATESTATE_MESSAGES,
		UPDATESTATE_PROCESS_1,
		UPDATESTATE_PROCESS_2,
		UPDATESTATE_PROCESS_DONE
	};

	typedef map<HANDLE, int> HandleToIntMap;

	class SexyAppBase : public ButtonListener, public DialogListener
	{
	public:

		ulong					mRandSeed;


		string					mCompanyName;
		string					mFullCompanyName;
		string					mProdName;
		SexyString				mTitle;
		string					mRegKey;
		string					mChangeDirTo;

		int						mRelaxUpdateBacklogCount; // app doesn't try to catch up for this many frames
		int						mPreferredX;
		int						mPreferredY;
		int						mWidth;
		int						mHeight;
		int						mFullscreenBits;
		double					mMusicVolume;
		double					mSfxVolume;
		double					mDemoMusicVolume;
		double					mDemoSfxVolume;
		bool					mNoSoundNeeded;
		bool					mWantFMod;
		bool					mCmdLineParsed;
		bool					mSkipSignatureChecks;
		bool					mStandardWordWrap;
		bool					mbAllowExtendedChars;

		HANDLE					mMutex;
		bool					mOnlyAllowOneCopyToRun;
		UINT					mNotifyGameMessage;
		CritSect				mCritSect;
		bool					mBetaValidate;
		uchar					mAdd8BitMaxTable[512];
		WidgetManager* mWidgetManager;
		DialogMap				mDialogMap;
		DialogList				mDialogList;
		DWORD					mPrimaryThreadId;
		bool					mSEHOccured;
		bool					mShutdown;
		bool					mExitToTop;
		bool					mIsWindowed;
		bool					mIsPhysWindowed;
		bool					mFullScreenWindow; // uses ChangeDisplaySettings to run fullscreen with mIsWindowed true
		bool					mForceFullscreen;
		bool					mForceWindowed;
		bool					mInitialized;
		bool					mProcessInTimer;
		DWORD					mTimeLoaded;
		HWND					mHWnd;
		HWND					mInvisHWnd;
		WNDCLASS				lp64fnWndProc;
		bool					mIsScreenSaver;
		bool					mAllowMonitorPowersave;
		WindowsMessageList		mDeferredMessages;
		bool					mNoDefer;
		bool					mFullScreenPageFlip;
		bool					mTabletPC;
		DDInterface* mDDInterface;
		bool					mAlphaDisabled;
		MusicInterface* mMusicInterface;
		bool					mReadFromRegistry;
		string					mRegisterLink;
		string					mProductVersion;
		Image* mCursorImages[NUM_CURSORS];
		HCURSOR					mOverrideCursor;
		bool					mIsOpeningURL;
		bool					mShutdownOnURLOpen;
		string					mOpeningURL;
		DWORD					mOpeningURLTime;
		DWORD					mLastTimerTime;
		DWORD					mLastBigDelayTime;
		double					mUnmutedMusicVolume;
		double					mUnmutedSfxVolume;
		int						mMuteCount;
		int						mAutoMuteCount;
		bool					mDemoMute;
		bool					mMuteOnLostFocus;
		MemoryImageSet			mMemoryImageSet;
		SharedImageMap			mSharedImageMap;
		bool					mCleanupSharedImages;

		int						mNonDrawCount;
		int						mFrameTime;

		bool					mIsDrawing;
		bool					mLastDrawWasEmpty;
		bool					mHasPendingDraw;
		double					mPendingUpdatesAcc;
		double					mUpdateFTimeAcc;
		DWORD					mLastTimeCheck;
		DWORD					mLastTime;
		DWORD					mLastUserInputTick;

		int						mSleepCount;
		int						mDrawCount;
		int						mUpdateCount;
		int						mUpdateAppState;
		int						mUpdateAppDepth;
		double					mUpdateMultiplier;
		bool					mPaused;
		int						mFastForwardToUpdateNum;
		bool					mFastForwardToMarker;
		bool					mFastForwardStep;
		DWORD					mLastDrawTick;
		DWORD					mNextDrawTick;
		int						mStepMode;  // 0 = off, 1 = step, 2 = waiting for step

		int						mCursorNum;
		SoundManager* mSoundManager;
		HCURSOR					mHandCursor;
		HCURSOR					mDraggingCursor;
		WidgetSafeDeleteList	mSafeDeleteList;
		bool					mMouseIn;
		bool					mRunning;
		bool					mActive;
		bool					mMinimized;
		bool					mPhysMinimized;
		bool					mIsDisabled;
		bool					mHasFocus;
		int						mDrawTime;
		ulong					mFPSStartTick;
		int						mFPSFlipCount;
		int						mFPSDirtyCount;
		int						mFPSTime;
		int						mFPSCount;
		bool					mShowFPS;
		int						mShowFPSMode;
		int						mScreenBltTime;
		bool					mAutoStartLoadingThread;
		bool					mLoadingThreadStarted;
		bool					mLoadingThreadCompleted;
		bool					mLoaded;
		bool					mYieldMainThread;
		bool					mLoadingFailed;
		bool					mCursorThreadRunning;
		bool					mSysCursor;
		bool					mCustomCursorsEnabled;
		bool					mCustomCursorDirty;
		bool					mLastShutdownWasGraceful;
		bool					mIsWideWindow;

		int						mNumLoadingThreadTasks;
		int						mCompletedLoadingThreadTasks;

		// For recording/playback of program control
		bool					mRecordingDemoBuffer;
		bool					mPlayingDemoBuffer;
		bool					mManualShutdown;
		string					mDemoPrefix;
		string					mDemoFileName;
		Buffer					mDemoBuffer;
		int						mDemoLength;
		int						mLastDemoMouseX;
		int						mLastDemoMouseY;
		int						mLastDemoUpdateCnt;
		bool					mDemoNeedsCommand;
		bool					mDemoIsShortCmd;
		int						mDemoCmdNum;
		int						mDemoCmdOrder;
		int						mDemoCmdBitPos;
		bool					mDemoLoadingComplete;
		HandleToIntMap			mHandleToIntMap; // For waiting on handles
		int						mCurHandleNum;

		typedef pair<string, int> DemoMarker;
		typedef list<DemoMarker> DemoMarkerList;
		DemoMarkerList			mDemoMarkerList;

		bool					mDebugKeysEnabled;
		bool					mEnableMaximizeButton;
		bool					mCtrlDown;
		bool					mAltDown;

		int						mSyncRefreshRate;
		bool					mVSyncUpdates;
		bool					mVSyncBroken;
		int						mVSyncBrokenCount;
		DWORD					mVSyncBrokenTestStartTick;
		DWORD					mVSyncBrokenTestUpdates;
		bool					mWaitForVSync;
		bool					mSoftVSyncWait;
		bool					mUserChanged3DSetting;
		bool					mAutoEnable3D;
		bool					mTest3D;
		DWORD					mMinVidMemory3D;
		DWORD					mRecommendedVidMemory3D;

		bool					mWidescreenAware;
		Rect					mScreenBounds;
		bool					mEnableWindowAspect;
		Ratio					mWindowAspect;

		StringWStringMap		mStringProperties;
		StringBoolMap			mBoolProperties;
		StringIntMap			mIntProperties;
		StringDoubleMap			mDoubleProperties;
		StringStringVectorMap	mStringVectorProperties;
		ResourceManager* mResourceManager;
		LONG					mOldWndProc;

	protected:
		void					RehupFocus();
		void					ClearKeysDown();
		bool					ProcessDeferredMessages(bool singleMessage);
		void					UpdateFTimeAcc();
		virtual bool			Process(bool allowSleep = true);
		virtual void			UpdateFrames();
		virtual bool			DoUpdateFrames();
		virtual void			DoUpdateFramesF(float theFrac);
		virtual void			MakeWindow();
		virtual void			EnforceCursor();
		virtual void			ReInitImages();
		virtual void			DeleteNativeImageData();
		virtual void			DeleteExtraImageData();

		// Loading thread methods	
		virtual void			LoadingThreadCompleted();
		static void				LoadingThreadProcStub(void* theArg);

		// Cursor thread methods
		void					CursorThreadProc();
		static void				CursorThreadProcStub(void* theArg);
		void					StartCursorThread();

		void					WaitForLoadingThread();
		void					ProcessSafeDeleteList();
		void					RestoreScreenResolution();
		void					DoExit(int theCode);

		void					TakeScreenshot();
		void					DumpProgramInfo();
		void					ShowMemoryUsage();

		// Registry helpers
		bool					RegistryRead(const string& theValueName, ulong* theType, uchar* theValue, ulong* theLength);
		bool					RegistryReadKey(const string& theValueName, ulong* theType, uchar* theValue, ulong* theLength, HKEY theMainKey = HKEY_CURRENT_USER);
		bool					RegistryWrite(const string& theValueName, ulong theType, const uchar* theValue, ulong theLength);

		// Demo recording helpers	
		void					ProcessDemo();

	public:
		SexyAppBase();
		virtual ~SexyAppBase();

		// Common overrides:
		virtual MusicInterface* CreateMusicInterface(HWND theHWnd);
		virtual void			InitHook();
		virtual void			ShutdownHook();
		virtual void			PreTerminate();
		virtual void			LoadingThreadProc();
		virtual void			WriteToRegistry();
		virtual void			ReadFromRegistry();
		virtual Dialog* NewDialog(int theDialogId, bool isModal, const SexyString& theDialogHeader, const SexyString& theDialogLines, const SexyString& theDialogFooter, int theButtonMode);
		virtual void			PreDisplayHook();

		// Public methods
		virtual void			BeginPopup();
		virtual void			EndPopup();
		virtual int				MsgBox(const string& theText, const string& theTitle = "Message", int theFlags = MB_OK);
		virtual int				MsgBox(const wstring& theText, const wstring& theTitle = L"Message", int theFlags = MB_OK);
		virtual long			MsgBox64(const string& the64bitText, const string& the64bitTitle = "Message", long theFlags = MB_OK);
		virtual long			MsgBox64(const wstring& the64bitText,  const wstring& the64bitTitle = L"Message", long theFlags = MB_OK);
		virtual void			Popup(const string& theString);
		virtual void			Popup(const wstring& theString);
		virtual void			LogScreenSaverError(const string& theError);
		virtual void			SafeDeleteWidget(Widget* theWidget);

		virtual void			URLOpenFailed(const string& theURL);
		virtual void			URLOpenSucceeded(const string& theURL);
		virtual bool			OpenURL(const string& theURL, bool shutdownOnOpen = false);
		virtual string		GetProductVersion(const string& thePath);

		virtual void			SEHOccured();
		virtual string		GetGameSEHInfo();
		virtual void			GetSEHWebParams(DefinesMap* theDefinesMap);
		virtual void			Shutdown();

		virtual void			DoParseCmdLine();
		virtual void			ParseCmdLine(const string& theCmdLine);
		virtual void			HandleCmdLineParam(const string& theParamName, const string& theParamValue);
		virtual void			HandleNotifyGameMessage(int theType, int theParam); // for HWND_BROADCAST of mNotifyGameMessage (0-1000 are reserved for SexyAppBase for theType)
		virtual void			HandleGameAlreadyRunning();

		virtual void			Start();
		virtual void			Init();
		virtual void			PreDDInterfaceInitHook();
		virtual void			PostDDInterfaceInitHook();
		virtual bool			ChangeDirHook(const char* theIntendedPath);
		virtual void			PlaySample(int theSoundNum);
		virtual void			PlaySample(int theSoundNum, int thePan);

		virtual double			GetMasterVolume();
		virtual double			GetMusicVolume();
		virtual double			GetSfxVolume();
		virtual bool			IsMuted();

		virtual void			SetMasterVolume(double theVolume);
		virtual void			SetMusicVolume(double theVolume);
		virtual void			SetSfxVolume(double theVolume);
		virtual void			Mute(bool autoMute = false);
		virtual void			Unmute(bool autoMute = false);

		void					StartLoadingThread();
		virtual double			GetLoadingThreadProgress();

		void					CopyToClipboard(const string& theString);
		string				GetClipboard();

		void					SetCursor(int theCursorNum);
		int						GetCursor();
		void					EnableCustomCursors(bool enabled);
		virtual DDImage* GetImage(const string& theFileName, bool commitBits = true);
		virtual SharedImageRef	GetSharedImage(const string& theFileName, const string& theVariant = "", bool* isNew = NULL);

		void					CleanSharedImages();
		void					PrecacheAdditive(MemoryImage* theImage);
		void					PrecacheAlpha(MemoryImage* theImage);
		void					PrecacheNative(MemoryImage* theImage);
		void					SetCursorImage(int theCursorNum, Image* theImage);

		DDImage* CreateCrossfadeImage(Image* theImage1, const Rect& theRect1, Image* theImage2, const Rect& theRect2, double theFadeFactor);
		void					ColorizeImage(Image* theImage, const Color& theColor);
		DDImage* CreateColorizedImage(Image* theImage, const Color& theColor);
		DDImage* CopyImage(Image* theImage, const Rect& theRect);
		DDImage* CopyImage(Image* theImage);
		void					MirrorImage(Image* theImage);
		void					FlipImage(Image* theImage);
		void					RotateImageHue(Sexy::MemoryImage* theImage, int theDelta);
		ulong					HSLToRGB(int h, int s, int l);
		ulong					RGBToHSL(int r, int g, int b);
		void					HSLToRGB(const ulong* theSource, ulong* theDest, int theSize);
		void					RGBToHSL(const ulong* theSource, ulong* theDest, int theSize);

		void					AddMemoryImage(MemoryImage* theMemoryImage);
		void					RemoveMemoryImage(MemoryImage* theMemoryImage);
		void					Remove3DData(MemoryImage* theMemoryImage);
		virtual void			SwitchScreenMode();
		virtual void			SwitchScreenMode(bool wantWindowed);
		virtual void			SwitchScreenMode(bool wantWindowed, bool is3d, bool force = false);
		virtual void			SetAlphaDisabled(bool isDisabled);

		virtual Dialog* DoDialog(int theDialogId, bool isModal, const SexyString& theDialogHeader, const SexyString& theDialogLines, const SexyString& theDialogFooter, int theButtonMode);
		virtual Dialog* GetDialog(int theDialogId);
		virtual void			AddDialog(int theDialogId, Dialog* theDialog);
		virtual void			AddDialog(Dialog* theDialog);
		virtual bool			KillDialog(int theDialogId, bool removeWidget, bool deleteWidget);
		virtual bool			KillDialog(int theDialogId);
		virtual bool			KillDialog(Dialog* theDialog);
		virtual int				GetDialogCount();
		virtual void			ModalOpen();
		virtual void			ModalClose();
		virtual void			DialogButtonPress(int theDialogId, int theButtonId);
		virtual void			DialogButtonDepress(int theDialogId, int theButtonId);

		virtual void			GotFocus();
		virtual void			LostFocus();
		virtual bool			IsAltKeyUsed(WPARAM wParam);
		virtual bool			DebugKeyDown(int theKey);
		virtual bool			DebugKeyDownAsync(int theKey, bool ctrlDown, bool altDown);
		virtual void			CloseRequestAsync();
		bool					Is3DAccelerated();
		bool					Is3DAccelerationSupported();
		bool					Is3DAccelerationRecommended();
		void					DemoSyncRefreshRate();
		void					Set3DAcclerated(bool is3D, bool reinit = true);
		virtual void			Done3dTesting();
		virtual string		NotifyCrashHook(); // return file name that you want to upload

		virtual bool			CheckSignature(const Buffer& theBuffer, const string& theFileName);
		virtual bool			DrawDirtyStuff();
		virtual void			Redraw(Rect* theClipRect);

		// Properties access methods
		bool					LoadProperties(const string& theFileName, bool required, bool checkSig);
		bool					LoadProperties();
		virtual void			InitPropertiesHook();

		// Resource access methods
		void					LoadResourceManifest();
		void					ShowResourceError(bool doExit = false);

		bool					GetBoolean(const string& theId);
		bool					GetBoolean(const string& theId, bool theDefault);
		int						GetInteger(const string& theId);
		int						GetInteger(const string& theId, int theDefault);
		double					GetDouble(const string& theId);
		double					GetDouble(const string& theId, double theDefault);
		SexyString				GetString(const string& theId);
		SexyString				GetString(const string& theId, const SexyString& theDefault);

		StringVector			GetStringVector(const string& theId);

		void					SetBoolean(const string& theId, bool theValue);
		void					SetInteger(const string& theId, int theValue);
		void					SetLong(const string& theId, long theValue);//64 bit.
		void					SetDouble(const string& theId, double theValue);//even larger than 64 bit... (E+308 digits). 
		void					SetString(const string& theId, const wstring& theValue);

		void					SetShort(const string& theId, short theValue);

		// Demo access methods
		bool					PrepareDemoCommand(bool required);
		void					WriteDemoTimingBlock();
		void					WriteDemoBuffer();
		bool					ReadDemoBuffer(string& theError);//UNICODE
		void					DemoSyncBuffer(Buffer* theBuffer);
		void					DemoSyncString(string* theString);
		void					DemoSyncInt(int* theInt);
		void					DemoSyncBool(bool* theBool);
		void					DemoAssertStringEqual(const string& theString);
		void					DemoAssertIntEqual(int theInt);
		void					DemoAddMarker(const string& theString);
		void					DemoRegisterHandle(HANDLE theHandle);
		void					DemoWaitForHandle(HANDLE theHandle);
		bool					DemoCheckHandle(HANDLE theHandle);


		// Registry access methods
		bool					RegistryGetSubKeys(const string& theKeyName, StringVector* theSubKeys);
		bool					RegistryReadString(const string& theValueName, string* theString);
		bool					RegistryReadInteger(const string& theValueName, int* theValue);
		bool					RegistryReadBoolean(const string& theValueName, bool* theValue);
		bool					RegistryReadData(const string& theValueName, uchar* theValue, ulong* theLength);
		bool					RegistryWriteString(const string& theValueName, const string& theString);
		bool					RegistryWriteInteger(const string& theValueName, int theValue);
		bool					RegistryWriteBoolean(const string& theValueName, bool theValue);
		bool					RegistryWriteData(const string& theValueName, const uchar* theValue, ulong theLength);
		bool					RegistryEraseKey(const SexyString& theKeyName);
		void					RegistryEraseValue(const SexyString& theValueName);

		// File access methods
		bool					WriteBufferToFile(const string& theFileName, const Buffer* theBuffer);
		bool					ReadBufferFromFile(const string& theFileName, Buffer* theBuffer, bool dontWriteToDemo = false);//UNICODE
		bool					WriteBytesToFile(const string& theFileName, const void* theData, unsigned long theDataLen);
		bool					FileExists(const string& theFileName);
		bool					EraseFile(const string& theFileName);

		// Misc methods
		virtual void			DoMainLoop();
		virtual bool			UpdateAppStep(bool* updated);
		virtual bool			UpdateApp();
		int						InitDDInterface();
		void					ClearUpdateBacklog(bool relaxForASecond = false);
		bool					IsScreenSaver();
		virtual bool			AppCanRestore();

		static LRESULT CALLBACK	WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK	WindowProc64(HWND hwnd, ULONG uLMsg, WPARAM wParam, LPARAM lParam);
	};
	extern SexyAppBase* gSexyAppBase;
}

#if WINAPI64
	long WINAPI64 Win64Main(HINSTANCE HInstance, HINSTANCE PreviousInstance, LPSTR LongCommandLine, long showcommand64);
#endif

#endif


//call this first in this library and explicity call this in your gameapp only for x64 builds...we already minimalized
//normal WinMain Process.  You still will need to keep the x86 configuration set until we *actually make this completely x64*.

/*This only a 64 bit *call*.  NOT the actual configuration set.  The x86 code will hook, or in this case, increase the address space since
we are allowed to use long in x86/win32.  */



