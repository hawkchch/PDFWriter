/*

PDF Writer printer driver.

Copyright (c) 2001 OpenBeOS. 

Authors: 
	Philippe Houdoin
	Simon Gauvin	
	Michael Pfeiffer
	
Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#ifndef JOBSETUPWINDOW_H
#define JOBSETUPWINDOW_H

#include <InterfaceKit.h>
#include "BlockingWindow.h"
#include "PrintUtils.h"

class JobSetupWindow : public HWindow 
{
public:
	// Constructors, destructors, operators...

							JobSetupWindow(BMessage *msg, const char *printer_name = NULL);
							~JobSetupWindow();

	typedef HWindow 		inherited;

	// public constantes
	enum	{
		NB_COPIES_MSG		= 'copy',
		ALL_PAGES_MGS		= 'all_',
		RANGE_SELECTION_MSG	= 'rnge',
		RANGE_FROM_MSG		= 'from',
		RANGE_TO_MSG		= 'to__',
		OK_MSG				= 'ok__',
		CANCEL_MSG			= 'cncl',
		DOC_INFO_MSG        = 'doci'
	};
			
	// Virtual function overrides
public:	
	virtual void 			MessageReceived(BMessage *msg);
	virtual bool 			QuitRequested();
	status_t 				Go();
	
	// From here, it's none of your business! ;-)
private:
	BString                 fPrinterName;
	long 					fExitSem;
	status_t				fResult;
	BMessage				*fSetupMsg;
	BMessage                fDocInfo;
	BRadioButton			*fAll;
	BRadioButton			*fRange;
	BTextControl			*fFrom;
	BTextControl			*fTo;
	
	void UpdateJobMessage();
};

#endif

