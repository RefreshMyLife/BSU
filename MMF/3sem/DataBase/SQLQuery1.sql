USE MilitaryUnit

--отсортировать по званиям командиров рот

SELECT [Soldiers].[ID],
	[Soldiers].[Name],
	[Soldiers].Surname,
	[Rank].[NameOfRank]
FROM [Soldiers], [Rank],[DivisionAndCompanies]
WHERE [Soldiers].[ID] = [DivisionAndCompanies].[CompanyCommanderID]
	AND [Soldiers].[RankID] = [Rank].[ID]
ORDER BY [Rank].[ID] DESC
