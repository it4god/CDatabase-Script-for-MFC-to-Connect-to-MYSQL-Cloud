
/*
##### How to Setting this database :
#1. Set the connection String to the MySQL Connection string wether it is local or remote ( Cloud )
#2. This Script has been tested both in local MySQL ann in Remote MySQL and works !
#3. In Firewall in our Laptop or PC must have outbound for port 3306. Give that permission


*/


/*######################################################################################################*/
#include "odbcinst.h" // Jeffrey Add this References/
#include "afxdb.h" //Jeffrey Add this References/

CMainFrame::CMainFrame()
{
	
	CDatabase database;
	CString UpdateQuery;
	CString InsertQuery;
	CString DeleteQuery;
	CString description = "Soli Deo Gloria";
	CString ID = "1";
	CString Table = "`tes`";
	CString command = "insert";
	CString DNS;
	//if (database.OpenEx(_T("DRIVER={MySQL ODBC 5.1 Driver};UID=root;PORT=3306;DATABASE=bible;SERVER=localhost;"), CDatabase::noOdbcDialog))
	//if (database.OpenEx(_T("DRIVER={MySQL ODBC 5.1 Driver};UID=limpin30_admin;PORT=3306;DATABASE=limpin30_analyzer;SERVER=151.106.103.31;P
	TRY{
	if (database.OpenEx(_T("DRIVER={MySQL ODBC 5.1 Driver};UID=root;PORT=3306;DATABASE=bible;SERVER=localhost;"), CDatabase::noOdbcDialog))
		{

		if (command == "insert")
		{
			InsertQuery = "INSERT INTO `tes` (`title`,`description`) VALUES ('Jesus Loves Me this I Know','Bless the Lord oh my soul')";
			database.ExecuteSQL(InsertQuery);
			database.Close();
		}
		else if (command == "update")
		{

			UpdateQuery = "UPDATE `tes` SET `description` = '" + description + "'  WHERE id = " + ID;
			database.ExecuteSQL(UpdateQuery);
			database.Close();
		}
		else if (command == "delete")
		{
			DeleteQuery = "DELETE FROM  " + Table + "  WHERE id = " + ID;
			database.ExecuteSQL(DeleteQuery);
			database.Close();
		}
		else if (command == "select")
		{

			CRecordset recset(&database);
			CString SqlString = "SELECT * FROM tes";
			recset.Open(CRecordset::forwardOnly, SqlString, CRecordset::readOnly);
			short nFields = recset.GetODBCFieldCount();
			CDBVariant var;
			CString desc, title;
			while (!recset.IsEOF())
			{
				recset.GetFieldValue((short)0, var, SQL_C_CHAR);
				recset.GetFieldValue(_T("title"), title);
				recset.GetFieldValue(_T("description"), desc);
				recset.MoveNext();
			}
			InsertQuery = "INSERT INTO `tes` (`title`,`description`) VALUES ('" + desc+ "', '" + title + "')";
			database.ExecuteSQL(InsertQuery);
			database.Close();
		
		}

	}
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Database error: ");
	}
	END_CATCH;
	m_pHelpVideosDlg=new CHelpVideosDlg(this);
}
