#include "stdafx.h"
#include "DataReaderListenerImpl.h"
#include "Common.h"

#include <ace/Log_Msg.h>
#include <ace/OS_NS_stdlib.h>

#include "DataReaderListenerImpl.h"
#include "DataATypeSupportC.h"
#include "DataATypeSupportImpl.h"

#include <iostream>

#include "TestOpenDDSDlg.h"

void CDataReaderListenerImpl::Init(CTestOpenDDSDlg* dlg)
{
	_dlg = dlg;
}

void CDataReaderListenerImpl::on_requested_deadline_missed(
	DDS::DataReader_ptr reader,
	const DDS::RequestedDeadlineMissedStatus& status)
{
	int a = 1;
}

void CDataReaderListenerImpl::on_requested_incompatible_qos(
	DDS::DataReader_ptr reader,
	const DDS::RequestedIncompatibleQosStatus& status)
{
	int a = 1;
}

void CDataReaderListenerImpl::on_sample_rejected(
	DDS::DataReader_ptr reader,
	const DDS::SampleRejectedStatus& status)
{
	int a = 1;
}

void CDataReaderListenerImpl::on_liveliness_changed(
	DDS::DataReader_ptr reader,
	const DDS::LivelinessChangedStatus& status)
{
	int a = 1;
}

void CDataReaderListenerImpl::on_data_available(DDS::DataReader_ptr reader)
{
	CStringA topicName(reader->get_topicdescription()->get_type_name());
	if (topicName == "TestA::DataA")
	{
		TestA::DataADataReader_var reader_i = TestA::DataADataReader::_narrow(reader);
		if (!reader_i) 
		{
			ASSERT(0);
			return;
		}

		TestA::DataASeq dataA;
		SampleInfoSeq sampleInfos;
		ReturnCode_t ret = reader_i->take(dataA, sampleInfos, DDS::LENGTH_UNLIMITED, ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
		if (ret == DDS::RETCODE_OK)
		{
			CString tmpLog;
			int sampleInfoLength = sampleInfos.length();
			for (int i = 0; i < sampleInfoLength; ++i)
			{
				if (sampleInfos[i].valid_data)
				{
					const char* oriBuf = dataA[i].dataSeq.get_buffer();
					int length = dataA[i].dataSeq.length();

					tmpLog.Format(L"���ģ�DataA name:%s pos:%d length:%d", CString(dataA[i].name), dataA[i].pos, dataA[i].length);
					_dlg->AppendMSG(tmpLog);
				}
			}
		}
		else
		{
			ASSERT(0);
		}

		reader_i->return_loan(dataA, sampleInfos);
	}
	else if (topicName == "TestA::DataB")
	{
		TestA::DataBDataReader_var reader_i = TestA::DataBDataReader::_narrow(reader);
		if (!reader_i)
		{
			ASSERT(0);
			return;
		}

		TestA::DataBSeq dataB;
		SampleInfoSeq sampleInfos;
		ReturnCode_t ret = reader_i->take(dataB, sampleInfos, DDS::LENGTH_UNLIMITED, ANY_SAMPLE_STATE, ANY_VIEW_STATE, ANY_INSTANCE_STATE);
		if (ret == DDS::RETCODE_OK)
		{
			CString tmpLog;
			int sampleInfoLength = sampleInfos.length();
			for (int i = 0; i < sampleInfoLength; ++i)
			{
				if (sampleInfos[i].valid_data)
				{
					tmpLog.Format(L"���ģ� DataB name:%s id:%d longitude:%lf", CString(dataB[i].name), dataB[i].id, dataB[i].longitude);
					_dlg->AppendMSG(tmpLog);
				}
			}
		}
		else
		{
			ASSERT(0);
		}

		reader_i->return_loan(dataB, sampleInfos);
	}




	
// 	TestA::DataA dataA;
// 	DDS::SampleInfo info;
// 
// 	DDS::ReturnCode_t error = reader_i->take_next_sample(dataA, info);
// 
// 	if (error == DDS::RETCODE_OK) {
// 		if (info.valid_data) {
// 			CString tmpLog;
// 			tmpLog.Format(L"�յ���DataA name:%s pos:%d length:%d", CString(dataA.name), dataA.pos, dataA.length);
// 			_dlg->AppendMSG(tmpLog);
// 		} 
// 
// 	}
// 	else {
// 		ACE_ERROR((LM_ERROR,
// 			ACE_TEXT("ERROR: %N:%l: on_data_available() -")
// 			ACE_TEXT(" take_next_sample failed!\n")));
// 	}
}

void CDataReaderListenerImpl::on_subscription_matched(
	DDS::DataReader_ptr reader,
	const DDS::SubscriptionMatchedStatus& status)
{
	int a = 1;
}

void CDataReaderListenerImpl::on_sample_lost(
	DDS::DataReader_ptr reader,
	const DDS::SampleLostStatus& status)
{
	int a = 1;
}
