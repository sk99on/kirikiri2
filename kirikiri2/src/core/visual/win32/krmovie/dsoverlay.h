//---------------------------------------------------------------------------
// ( part of KRMOVIE.DLL )
// (c)2001-2004, W.Dee <dee@kikyou.info>
//---------------------------------------------------------------------------

/*
	We must separate this module because sucking MS library has a lack of
	compiler portability.

	This requires DirectX7 or later or Windows Media Player 6.4 or later for
	playbacking MPEG streams.


	Modified by T.Imoto <http://www.kaede-software.com>
*/

#ifndef __DSOVERLAY_H__
#define __DSOVERLAY_H__

#include "dsmovie.h"

//----------------------------------------------------------------------------
//! @brief �I�[�o�[���C �r�f�I�`��N���X
//----------------------------------------------------------------------------
class tTVPDSVideoOverlay : public tTVPDSMovie
{
private:
	CComPtr<IVideoWindow>	m_VideoWindow;
	CComPtr<IBasicAudio>	m_BasicAudio;

	//----------------------------------------------------------------------------
	//! @brief	  	IVideoWindow���擾����
	//! @return		IVideoWindow�C���^�[�t�F�C�X
	//----------------------------------------------------------------------------
	IVideoWindow *VideoWindow()
	{
		assert( m_VideoWindow.p );
		return m_VideoWindow;
	}
	//----------------------------------------------------------------------------
	//! @brief	  	IBasicAudio���擾����
	//! @return		IBasicAudio�C���^�[�t�F�C�X
	//----------------------------------------------------------------------------
	IBasicAudio *Audio()
	{
		assert( m_BasicAudio.p );
		return m_BasicAudio;
	}

public:
	tTVPDSVideoOverlay();
	virtual ~tTVPDSVideoOverlay();

	virtual const wchar_t* __stdcall BuildGraph( HWND callbackwin, IStream *stream,
	const wchar_t * streamname, const wchar_t *type, unsigned __int64 size );

	virtual void __stdcall ReleaseAll();

	virtual const wchar_t* __stdcall SetWindow(HWND window);
	virtual const wchar_t* __stdcall SetMessageDrainWindow(HWND window);
	virtual const wchar_t* __stdcall SetRect(RECT *rect);
	virtual const wchar_t* __stdcall SetVisible(bool b);

	virtual const wchar_t* __stdcall Play();
};

#endif	// __DSOVERLAY_H__