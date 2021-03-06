USE MilitaryUnit

--вывести информацию о командире 1 роты

declare @num bigint
set @num = 1

SELECT [Name]
	,[Surname]
	,[NameOfRank]
	,[NameOfForm]
FROM(
	SELECT [Soldiers].[ID]
		,[Soldiers].[Name]
		,[Soldiers].[Surname]
		,[Rank].[NameOfRank]
		,[FormsOfMilitaryService].[NameOfForm]
	FROM [Soldiers], [Rank], [FormsOfMilitaryService]
	WHERE [Soldiers].[RankID] = [Rank].[ID] 
		AND [Soldiers].[FormOfServiceID] = [FormsOfMilitaryService].[ID]
) AS temp
WHERE ID IN(
	SELECT [DivisionAndCompanies].[CompanyCommanderID]
	FROM [DivisionAndCompanies]
	WHERE [DivisionAndCompanies].[CompanyID] = @num
)